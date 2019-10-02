import os
import sys
import urllib.request
import zipfile

import numpy as np
import tensorflow as tf
from keras.preprocessing.image import ImageDataGenerator


class Caltech42:
    labels = [
        "airplanes", "bonsai", "brain", "buddha", "butterfly",
        "car_side", "chair", "chandelier", "cougar_face", "crab",
        "crayfish", "dalmatian", "dragonfly", "elephant", "ewer",
        "faces", "flamingo", "grand_piano", "hawksbill", "helicopter",
        "ibis", "joshua_tree", "kangaroo", "ketch", "lamp", "laptop",
        "llama", "lotus", "menorah", "minaret", "motorbikes", "schooner",
        "scorpion", "soccer_ball", "starfish", "stop_sign", "sunflower",
        "trilobite", "umbrella", "watch", "wheelchair", "yin_yang",
    ]
    MIN_SIZE, C, LABELS = 224, 3, len(labels)

    _URL = "https://ufal.mff.cuni.cz/~straka/courses/npfl114/1819/datasets/caltech42.zip"

    class Dataset:
        def __init__(self, data, augment, seed=42, one_hot=False):
            data['labels'] = np.array(data['labels'])
            for i in range(len(data['images'])):
                if data['images'][i].shape[2] == 1:
                    data['images'][i] = np.dstack([data['images'][i]]*3)
            data['images'] = np.array(data['images'])
            if one_hot:
                labels_new = np.zeros((len(data['labels']), Caltech42.LABELS))
                for i in range(len(data['labels'])):
                    if data['labels'][i] < Caltech42.LABELS:  # test has labels 255
                        labels_new[i][data['labels'][i]] = 1
                data['labels'] = labels_new

            self._data = data
            self._size = len(self._data["images"])

        def batches(self, size=None):
            size = size if size else self._size
            idg = ImageDataGenerator(rotation_range=25, width_shift_range=30, height_shift_range=30,
                                     zoom_range=0, brightness_range=(0.95, 1.05), shear_range=0.01, horizontal_flip=True)
            idg.fit(self._data['images'], seed=42)
            idg_f = idg.flow(
                self._data['images'], y=self._data['labels'], shuffle=True, batch_size=size)
            return idg_f

        @property
        def data(self):
            return self._data

        @property
        def size(self):
            return self._size

    # resize in ['bilinear', 'crop_pad', 'bilinear_pad']
    def __init__(self, width=224, height=224, resize='bilinear', one_hot=False):
        path = os.path.basename(self._URL)
        if not os.path.exists(path):
            print("Downloading Caltech42 dataset...", file=sys.stderr)
            urllib.request.urlretrieve(self._URL, filename=path)

        with zipfile.ZipFile(path, "r") as caltech42_zip:
            for dataset in ["train", "dev", "test"]:
                data = {"images": [], "labels": []}
                for name in sorted(caltech42_zip.namelist()):
                    if not name.startswith(dataset) or not name.endswith(".jpg"):
                        continue
                    with caltech42_zip.open(name, "r") as image_file:
                        # TODO: is the first numpy() necessary?
                        img = tf.io.decode_jpeg(image_file.read()).numpy()

                        if resize == 'bilinear':
                            img = tf.image.resize(
                                img, (width, height)).numpy()  # .astype('uint8')
                        elif resize == 'crop_pad':
                            img = tf.image.resize_image_with_crop_or_pad(
                                img, width, height).numpy()  # .astype('uint8')
                        elif resize == 'bilinear_pad':
                            img = tf.image.resize_image_with_pad(
                                img, width, height).numpy()  # .astype('uint8')
                        else:
                            raise Exception(
                                "Unknown resize argument: `" + str(resize) + "`")

                        data["images"].append(img)

                    if "_" in name:
                        data["labels"].append(
                            self.labels.index(name[name.index("_")+1:-4]))
                    else:
                        data["labels"].append(-1)

                if all(map(lambda i: type(i) == np.ndarray and i.dtype == np.float32 and i.shape == (self.MIN_SIZE, self.MIN_SIZE, self.C),
                           data["images"])):
                    data["images"] = np.array(data["images"])
                data["labels"] = np.array(data["labels"], dtype=np.uint8)
                setattr(self, dataset, self.Dataset(
                    data, augment=dataset == "train", one_hot=one_hot))
