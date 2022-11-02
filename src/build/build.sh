#!/bin/sh

OS=$(uname)

cd build
$1 ../qtViewer/*.pro
make

mkdir build
mv *.o build
mv *.cpp build
mv *.h build
mv .qmake.stash build
mv qtViewer.app build
mv Makefile build