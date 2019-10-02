import os
import sys
import urllib.request

import numpy as np

class FashionMasks:
    H, W, C = 28, 28, 1
    LABELS = 10
    TRAIN_TOTAL = 55000

    _URL = "https://ufal.mff.cuni.cz/~straka/courses/npfl114/1819/datasets/fashion_masks_data.npz"

    class Dataset:
        def __init__(self, data, shuffle_batches, seed=42):
            self._data = data
            self._data["images"] = self._data["images"].astype(np.float32) / 255
            self._size = len(self._data["images"])

            self._shuffler = np.random.RandomState(seed) if shuffle_batches else None

        @property
        def data(self):
            return self._data

        @property
        def size(self):
            return self._size

        def batches(self, size=None):
            permutation = self._shuffler.permutation(self._size) if self._shuffler else np.arange(self._size)
            while len(permutation):
                batch_size = min(size or np.inf, len(permutation))
                batch_perm = permutation[:batch_size]
                permutation = permutation[batch_size:]

                batch = {}
                for key in self._data:
                    batch[key] = self._data[key][batch_perm]
                yield batch

    def __init__(self):
        path = os.path.basename(self._URL)
        if not os.path.exists(path):
            print("Downloading FashionMasks dataset...", file=sys.stderr)
            urllib.request.urlretrieve(self._URL, filename=path)

        fashion_masks = np.load(path)
        for dataset in ["train", "dev", "test"]:
            data = dict((key[len(dataset) + 1:], fashion_masks[key]) for key in fashion_masks if key.startswith(dataset))
            setattr(self, dataset, self.Dataset(data, shuffle_batches=dataset == "train"))