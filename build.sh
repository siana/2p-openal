#!/bin/bash
VERBOSE="VERBOSE=1"
case $OSTYPE in
	linux*)
		FLAGS="-O3 -msse -mtune=pentium4 -mfpmath=sse -ffast-math -frounding-math --param inline-unit-growth=100"
		;;
	cygwin*)
		exit 1
		;;
	darwin*)
		exit 1
		;;
esac

CWD=`pwd`
rm -r build
mkdir build
cd build
cmake .. -DCMAKE_C_FLAGS:STRING="$FLAGS" -DCMAKE_BUILD_TYPE:STRING=Release
make -j2 $VERBOSE
rm libopenal.so.1
mv libopenal.so.1.* libopenal.so.1
chmod 644 libopenal.so.1
strip --strip-unneeded libopenal.so.1
rm libopenal.so
ln -s libopenal.so.1 libopenal.so
cd ../freealut-1.1.0
rm -r build
mkdir build
cd build
cmake .. -DCMAKE_C_FLAGS:STRING="$FLAGS" -DCMAKE_CXX_FLAGS:STRING="$FLAGS" -DCMAKE_BUILD_TYPE:STRING=Release -DOPENAL_LIB_DIR:STRING="$CWD/build" -DOPENAL_INCLUDE_DIR="$CWD/include"
make -j2 $VERBOSE
cd ../../
rm -r pak
mkdir pak
cd pak
mkdir -p libraries/include
cp -r ../include/AL libraries/include
cp -r ../freealut-1.1.0/include/AL libraries/include
LIBDIR=libraries/i686-linux/lib_release_client
mkdir -p $LIBDIR
cp ../build/libopenal.so* $LIBDIR
cp ../freealut-1.1.0/build/libalut.so $LIBDIR
mkdir LICENSES
cp ../COPYING LICENSES/openal.txt
DATE=`date +%y%m%d`
tar -cjvf "openal-linux-$DATE.tar.bz2" libraries/ LICENSES/
md5sum -b "openal-linux-$DATE.tar.bz2"
