# This is an experiment in making an automated C/C++ code splitter for SWIG generated output

```
./cc-splitter ~/src/node-magickwand/swig/Magick++.cxx -- -DMAGICKCORE_HDRI_ENABLE=1 -DMAGICKCORE_QUANTUM_DEPTH=16 -D__STDC_CONSTANT_MACROS -D__STDC_LIMIT_MACROS -I/usr/include/node -I/usr/include/node/napi -I/home/mmom/src/node-magickwand/deps/ImageMagick/Magick++/lib -I/home/mmom/src/node-magickwand/deps/ImageMagick -c

./cc-splitter ../splitter.cc -- -I/usr/lib/llvm-15/include/
./cc-splitter ../test.cc -- -I/usr/lib/llvm-15/include/
```
