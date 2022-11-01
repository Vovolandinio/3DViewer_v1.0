#!/bin/sh

OS=$(uname)

cd build
$1 ../qtViewer/*.pro
make
elif [ ${OS} = Darwin ]; then
    cp -r viewer* ../
fi