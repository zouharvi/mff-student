import os
import sys
import urllib.request
import random
import numpy as np
from scipy import ndimage
from keras.utils import to_categorical

class ModelNet:
    # The D, H, W are set in the constructor depending
    # on requested resolution and are only instance variables.
    D, H, W, C = None, None, None, 1
    LABELS = [
        "bathtub", "bed", "chair", "desk", "dresser",
        "monitor", "night_stand", "sofa", "table", "toilet",
    ]

    _URL = "https://ufal.mff.cuni.cz/~straka/courses/npfl114/1819/datasets/modelnet{}.npz"

    class Dataset:
        def __init__(self, data, is_train, seed=42):
            self._data = data

            self._shuffler = np.random.RandomState(seed) if is_train else None
            self._data['labels'] = to_categorical(self._data['labels'])

            if is_train:
                orig_voxels = np.array(self._data['voxels'])
                orig_labels = np.array(self._data['labels'])
                for k in [1, 2, 3]:
                    rotated = np.array(orig_voxels)
                    for i in range(len(rotated)):
                        rotated[i] = np.rot90(rotated[i], k=k, axes=(0,1))
                    self._data['voxels'] = np.append(self._data['voxels'], rotated, axis=0)
                    self._data['labels'] = np.append(self._data['labels'], orig_labels, axis=0)
                # tmp = np.load('modelnet32_all.npz')
                # print('Before: ', self._data['voxels'].shape)
                # self._data['voxels'] = np.append(self._data['voxels'], tmp['voxels'], axis=0)
                # print('After: ', self._data['voxels'].shape)
                # self._data['labels'] = np.append(self._data['labels'], tmp['labels'], axis=0)
            self._size = len(self._data["voxels"])

        @property
        def data(self):
            return self._data

        @property
        def size(self):
            return self._size

        def cutout(self, voxels, prob):
            if random.random() < prob:
                startX = random.randrange(0, voxels.shape[0])
                startY = random.randrange(0, voxels.shape[1])
                startZ = random.randrange(0, voxels.shape[2])
                lenX = random.randrange(3, 15)
                lenY = random.randrange(3, 15)
                lenZ = random.randrange(3, 15)
                for x in range(startX, min(voxels.shape[0], startX+lenX)):
                    for y in range(startY, min(voxels.shape[1], startY+lenY)):
                        for z in range(startZ, min(voxels.shape[2], startZ+lenZ)):
                            voxels[x][y][z] = 0
                return voxels
            else:
                return voxels
        
        def zoom(self, voxels, size):
            assert(size==32)
            voxels = voxels.reshape(size, size, size).astype(np.float32)
            typ = random.randrange(0, 6)
            if typ == 0:            
                pass
                # voxels = np.pad(ndimage.zoom(voxels, 0.25), 12, 'constant')
            elif typ == 1:
                voxels = np.pad(ndimage.zoom(voxels, 0.5), 8, 'constant')
            elif typ == 2:            
                voxels = np.pad(ndimage.zoom(voxels, 0.75), 4, 'constant')
            elif typ == 3:            
                voxels = ndimage.zoom(voxels, 1.25)[4:-4,4:-4,4:-4]
            elif typ == 4:            
                voxels = ndimage.zoom(voxels, 1.5)[8:-8,8:-8,8:-8]
            elif typ == 5:
                pass            
                # voxels = ndimage.zoom(voxels, 2)[16:-16,16:-16,16:-16]
            else:
                pass
            
            return voxels.reshape(size, size, size, 1)


        def batches(self, batch_size=None):
            while True:
                permutation = self._shuffler.permutation(self._size) if self._shuffler else np.arange(self._size)
                while len(permutation):
                    batch_size = min(batch_size or np.inf, len(permutation))
                    batch_perm = permutation[:batch_size]
                    permutation = permutation[batch_size:]

                    voxels_tmp = np.array(self._data['voxels'][batch_perm])
                    labels_tmp = np.array(self._data['labels'][batch_perm])

                    for i in range(batch_size):
                        # rotation
                        rotation = random.randint(0, 4)
                        voxels_tmp[i] = np.rot90(voxels_tmp[i], k=rotation, axes=(0,1))
                        
                        # cutout
                        # before = (np.sum(voxels_tmp))
                        voxels_tmp[i] = self.cutout(voxels_tmp[i], 0.9)
                        # after = (np.sum(voxels_tmp))
                        # if before != after:
                        #     print('before: {}, after: {}, diff: {}'.format(before,after,before-after))
                        voxels_tmp[i] = self.zoom(voxels_tmp[i], 32)


                    # batch = {}
                    # for key in self._data:
                    #     batch[key] = self._data[key][batch_perm]
                    yield (voxels_tmp, labels_tmp)

    # The resolution parameter can be either 20 or 32.
    def __init__(self, resolution):
        assert resolution in [20, 32], "Only 20 or 32 resolution is supported"

        self.D = self.H = self.W = resolution
        url = self._URL.format(resolution)

        path = os.path.basename(url)
        if not os.path.exists(path):
            print("Downloading {} dataset...".format(path), file=sys.stderr)
            urllib.request.urlretrieve(url, filename=path)

        mnist = np.load(path)
        for dataset in ["train", "dev", "test"]:
            data = dict((key[len(dataset) + 1:], mnist[key]) for key in mnist if key.startswith(dataset))
            setattr(self, dataset, self.Dataset(data, is_train=dataset == "train"))