import os
import sys
import urllib.request

import numpy as np
from keras.preprocessing.image import ImageDataGenerator


class FashionMasks:
    H, W, C = 28, 28, 1
    LABELS = 10
    TRAIN_TOTAL = 55000

    data_all = dict()

    _URL = "https://ufal.mff.cuni.cz/~straka/courses/npfl114/1819/datasets/fashion_masks_data.npz"

    class Dataset:
        def __init__(self, data, shuffle_batches, seed=42, fashion_masks=None, augment=False):
            self._data = data
            self._fashion_masks = fashion_masks
            self._augment = augment
            self._data["images"] = self._data["images"].astype(
                np.float32) / 255
            self._size = len(self._data["images"])

            self._shuffler = np.random.RandomState(
                seed) if shuffle_batches else None
            for kind in ["images", "masks", "labels"]:
                if kind not in fashion_masks.data_all.keys():
                    fashion_masks.data_all[kind] = self._data[kind]
                else:
                    fashion_masks.data_all[kind] = np.append(
                        fashion_masks.data_all[kind], self._data[kind], axis=0)

        @property
        def data(self):
            return self._data

        @property
        def size(self):
            return self._size

        def batches(self, size=None):
            size = size if size else self._size

            permutation = np.random.permutation(self._size)
            # print(permutation)

            d_images = self._data['images'][permutation]
            d_masks = self._data['masks'][permutation]
            d_labels = self._data['labels'][permutation]

            idg_args = dict(rotation_range=0, featurewise_center=True, featurewise_std_normalization=True,
                 width_shift_range=0, height_shift_range=0, zoom_range=0, horizontal_flip=False)
            mdg_args = dict(rotation_range=0, featurewise_center=False, featurewise_std_normalization=False,
                 width_shift_range=0, height_shift_range=0, zoom_range=0, horizontal_flip=False)
            if not self._augment: 
                idg_args = dict(featurewise_center=True, featurewise_std_normalization=True)
                mdg_args = dict(featurewise_center=False, featurewise_std_normalization=False)
            
            idg = ImageDataGenerator(**idg_args)
            mdg = ImageDataGenerator(**mdg_args)

            idg.fit(self._fashion_masks.data_all['images'], seed=42)
            mdg.fit(self._fashion_masks.data_all['masks'], seed=42)

            flow_args = dict(shuffle=False, batch_size=size)
            idg_f = idg.flow(d_images, y=d_labels, **flow_args)
            mdg_f = mdg.flow(d_masks, **flow_args)

            # Image.fromarray(mask.reshape(28,28)*255.0).show()

            for i in range(int(self._size/size)):
                images, labels = next(idg_f)
                masks = next(mdg_f)
                yield {'images': images, 'labels': labels, 'masks': masks}

    def __init__(self):
        path = os.path.basename(self._URL)
        if not os.path.exists(path):
            print("Downloading FashionMasks dataset...", file=sys.stderr)
            urllib.request.urlretrieve(self._URL, filename=path)

        fashion_masks = np.load(path)
        for dataset in ["train", "dev", "test"]:
            data = dict((key[len(dataset) + 1:], fashion_masks[key])
                        for key in fashion_masks if key.startswith(dataset))
            setattr(self, dataset, self.Dataset(
                data, shuffle_batches=dataset == "train", fashion_masks=self, augment=dataset == "train"))
