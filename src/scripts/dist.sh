#!/bin/sh

cd qtViewer
mkdir 3D_viewer_dist
cp *.c 3D_viewer_dist
cp *.h 3D_viewer_dist
cp qtViewer.pro.user 3D_viewer_dist
cp *.pro 3D_viewer_dist
cp *.cpp 3D_viewer_dist
cp *.ui 3D_viewer_dist
cp *.sh 3D_viewer_dist
cp clang-format 3D_viewer_dist
tar -czf 3D_viewer_dist.tar 3D_viewer_dist/
