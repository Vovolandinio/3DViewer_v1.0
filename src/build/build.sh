#!/bin/sh

cd build
$1 ../qtViewer/*.pro
make

mkdir $HOME/Applications/build
mv *.o $HOME/Applications/build
mv *.cpp $HOME/Applications/build
mv *.h $HOME/Applications/build
mv .qmake.stash $HOME/Applications/build
mv qtViewer.app $HOME/Applications/build
mv Makefile $HOME/Applications/build