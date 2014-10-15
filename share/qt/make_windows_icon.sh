#!/bin/bash
# create multiresolution windows icon
ICON_SRC=../../src/qt/res/icons/gapcoin.png
ICON_DST=../../src/qt/res/icons/gapcoin.ico
convert ${ICON_SRC} -resize 16x16 gapcoin-16.png
convert ${ICON_SRC} -resize 32x32 gapcoin-32.png
convert ${ICON_SRC} -resize 48x48 gapcoin-48.png
convert gapcoin-16.png gapcoin-32.png gapcoin-48.png ${ICON_DST}

