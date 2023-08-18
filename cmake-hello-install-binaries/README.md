# Using Abseil via CMake Installation Binaries

Scaffolding for reproducing the [approach outlined here](https://abseil.io/docs/cpp/tools/cmake-installs).

i.e (using a user-defined (not-default) `CMAKE_INSTALL_PREFIX`), assumes `cwd` is the same as this file:

Clone the abseil repo:

```bash
$ export REPO_PATH=`pwd`
$ cd .. # navigate to the base repo dir
$ git clone https://github.com/abseil/abseil-cpp.git
$ cd abseil-cpp
$ cmake -S . -B build/ -DCMAKE_INSTALL_PREFIX=$REPO_PATH/abseil-install -DCMAKE_CXX_STANDARD=14 -G Ninja
$ cmake --build build/ --target install
$ cd $REPO_PATH
```

Now, back in the repo directory:

```bash
$ cmake -S . -B build -DCMAKE_PREFIX_PATH=$REPO_PATH/abseil-install -G Ninja
$ cmake --build build/ --verbose
```
