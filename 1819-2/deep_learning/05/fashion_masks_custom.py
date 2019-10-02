from fashion_masks_data import FashionMasks
from PIL import Image

def arr2img(data):
    return (data*255).reshape(28,28)

def showImg(data):
    Image.fromarray(arr2img(data)).show()

def showDev(index):
    showImg(fm.dev.data['images'][index])