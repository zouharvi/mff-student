#!/bin/env python3

from PIL import Image, ImageDraw, ImageFont
import os

IMG_DIR_SRC = '../caltech42/test'
IMG_DIR_TARGET = '../caltech42/test_labeled'
LABELS_FILE = 'test_labels_both.txt'

os.makedirs(IMG_DIR_TARGET, exist_ok=True)

with open(LABELS_FILE) as f_lab:
    labels = [x.replace('\n', '') for x in f_lab.readlines()]



font = ImageFont.truetype('/usr/share/fonts/gnu-free/FreeMonoBold.ttf', size=16)

for filename in os.listdir(IMG_DIR_SRC):
    if filename.endswith(".jpg"): 
        img = Image.open(os.path.join(IMG_DIR_SRC, filename)).convert('RGB')
        num = int(filename[:-4])
        label = labels[num]
        ImageDraw.Draw(img).rectangle((0, 0, 160, 18), fill=(0,0,0))
        ImageDraw.Draw(img).text(text=labels[num], xy=(0,0), font=font)
        img.save(os.path.join(IMG_DIR_TARGET, filename))

img.show()