#! /bin/sh

TOP_DIR=$(pwd)
BUILDROOT_TARGET_PATH=$(pwd)/../../buildroot/output/target/
QMAKE=$(pwd)/../../buildroot/output/host/usr/bin/qmake

#get parameter for "-j2~8 and clean"
result=$(echo "$1" | grep -Eo '*clean')
if [ "$result" = "" ];then
        mulcore_cmd=$(echo "$1" | grep '^-j[0-9]\{1,2\}$')
elif [ "$1" = "clean" ];then
        make clean
elif [ "$1" = "distclean" ];then
        make clean
else
	mulcore_cmd=-j4
fi

#qmake and build target
$QMAKE
make $mulcore_cmd
cp $TOP_DIR/Carmachine $BUILDROOT_TARGET_PATH/usr/bin/
make clean
echo "Carmachine app is ready."

#call just for buid_all.sh
if [ "$1" = "cleanthen" ] || [ "$2" = "cleanthen" ];then
        make clean
fi
