KRuleEngine C++ Implementation
==============================

Build
-----
Make a directory to build KRuleEngine in.
Then, execute cmake towards the directory containing the src folder.
CMake needs to know were to look for Qt5 Qt5Core and Qt5Quick.
If those are not installed on the system but locally compiled you need
to point them out. Example of CMAKE_PREFIX_PATH: ~/Qt/5.5/gcc_64/lib/cmake

```bash
mkdir build
cd build
cmake -DCMAKE_PREFIX_PATH=<path to Qt5 Qt5Core and Qt5Quick cmake> ..
make
```
