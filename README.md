# cpp-memory-master
Master of c++ smart pointer


```
~$: git clone https://www.github.com/YeongJunKim/cpp-memory-master
~$: cd cpp-memory-master
~$: mkdir build
~$: cd build
~$: cmake ..
~$: make
```

### openCV install

1. Check openCV
```
pkg-config --modversion opencv
```
result (not installed)
```
Package opencv was not found in the pkg-config search path.
Perhaps you should add the directory containing `opencv.pc'
to the PKG_CONFIG_PATH environment variable
No package 'opencv' found
```
result (installed opencv 2.4.9.1)
```
2.4.9.1
```

2. Uninstall openCV

uninstall package
```
sudo apt-get purge  libopencv* python-opencv
sudo apt-get autoremove
```
```
 sudo find /usr/local/ -name "*opencv*" -exec rm -i {} \;
```


```
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install build-essential cmake
sudo apt-get install pkg-config
sudo apt-get install libjpeg-dev libtiff5-dev libpng-dev
sudo apt-get install libavcodec-dev libavformat-dev libswscale-dev libxvidcore-dev libx264-dev libxine2-dev
sudo apt-get install libv4l-dev v4l-utils
sudo apt-get install libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev 
sudo apt-get install libgtk2.0-dev
sudo apt-get install mesa-utils libgl1-mesa-dri libgtkgl2.0-dev libgtkglext1-dev  
sudo apt-get install libatlas-base-dev gfortran libeigen3-dev
sudo apt-get install python2.7-dev python3-dev python-numpy python3-numpy
```

3. OpenCV setting & install

```
wget -O opencv.zip https://github.com/opencv/opencv/archive/4.2.0.zip
unzip opencv.zip
```