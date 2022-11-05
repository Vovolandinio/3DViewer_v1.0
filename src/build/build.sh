#!/bin/sh

cd build
$1 ../qtViewer/*.pro
make

mkdir Viewer

mkdir Viewer
mv *.o Viewer
mv *.cpp Viewer
mv *.h Viewer
mv .qmake.stash Viewer
mv qtViewer.app Viewer
mv Makefile Viewer