#include <stdio.h>

class Test {
  int x;
public:
  Test();
  int method();
};

Test::Test() : x(1) {}

int Test::method() {
  return 1;
}
