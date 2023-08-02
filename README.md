# This used to be an experiment in making an automated C/C++ code splitter for SWIG generated output

(but alas, this won't be practical if running after the preprocessor)

# Now it is the missing working tutorial for libclang

`splitter.cc` is the plumbing that allows you to create your plugin and to process the compiler options
`ast.cc` is the frontend plugin itself, `ASTSplitter::TraverseDecl` will get called for each compiler *declarator* (which is a declaration, a statement or a definition).

This example will print all global declarations and definitions, discriminating between declaration and a definition, in a C++ source file.

```
./cc-splitter ~/src/node-magickwand/swig/Magick++.cxx -- -DMAGICKCORE_HDRI_ENABLE=1 -DMAGICKCORE_QUANTUM_DEPTH=16 -D__STDC_CONSTANT_MACROS -D__STDC_LIMIT_MACROS -I/usr/include/node -I/usr/include/node/napi -I/home/mmom/src/node-magickwand/deps/ImageMagick/Magick++/lib -I/home/mmom/src/node-magickwand/deps/ImageMagick -c

./cc-splitter ../splitter.cc -- -I/usr/lib/llvm-15/include/
./cc-splitter ../test.cc -- -I/usr/lib/llvm-15/include/
```
