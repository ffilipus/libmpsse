libmpsse
========

Open source library for SPI/I2C control via FTDI chips. Can be built on Windows thanks to [CMake](https://cmake.org/) and [MinGW](http://mingw-w64.org/).

## Installation
Installation steps for Linux:
```
git clone https://github.com/ffilipus/libmpsse.git
cd libmpsse
mkdir build
cd build
cmake ..
make
sudo make install
```
Windows installation steps are similar. Can be handled with CMake GUI, compiling with MinGW make and copying **libmpsse.a** and **mpsse.h** to corresponding **lib** and **include** directories in MinGW installation.
