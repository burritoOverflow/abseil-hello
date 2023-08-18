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

For shared instead of static libraries, you can add `-DBUILD_SHARED_LIBS:BOOL=ON`

If opting for shared libraries, the following can be used to run the executable (recall that the libraries are installed locally: in: `$REPO_PATH/abseil-install/lib` via the `CMAKE_INSTALL_PREFIX`):

```bash
env LD_LIBRARY_PATH=./abseil-install/lib ./build/hello_world
```

Now, back in the repo directory:

```bash
$ cmake -S . -B build -DCMAKE_PREFIX_PATH=$REPO_PATH/abseil-install -G Ninja
$ cmake --build build/ --verbose
```
