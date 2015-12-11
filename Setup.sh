#!/bin/sh

function printMsg {
    tput setaf 2
    echo $1
    tput sgr0
}

function createWinBin {

    printMsg "Creating Windows binaries"
    mkdir -p ./bin/Win
    COMPILER="i586-mingw32-c++"
    WLIBS="-lopengl32 -lglu32 -lglu32 -lgdi32 -mwindows -lmingw32"
    WNAME="Backmaze.exe"
    cd ./src
    make -e CXX=$COMPILER LIBS="$WLIBS" OCCOBJECTS="" NAME=$WNAME
    mv $WNAME ../bin/Win/
    make clean
    cd ..
    cp ./resources/* ./bin/Win/


}

function createAppleCocoa {
    printMsg "Creating OS X Cocoa binaries"
    mkdir -p ./bin/Backmaze.app
    cd ./src
    make
    mv Backmaze ../bin/BackMaze.app
    make clean
    cd ..
    cp ./resources/* ./bin/Backmaze.app
    cp ./platforms/OSX/* ./bin/Backmaze.app
}

function clean {
    rm -rf ./bin
    cd src && make clean
}

mkdir -p ./bin

for i in "$@"
do
if [ $i = "Win" ]; then createWinBin
elif [ $i = "Apple" ]; then createAppleCocoa
elif [ $i = "All" ]; then createWinBin && createAppleCocoa
elif [ $i = "About" ]; then printMsg "Created by Heiko van der Heijden Copyright 2015"
elif [ $i = "clean" ]; then clean
fi

done
