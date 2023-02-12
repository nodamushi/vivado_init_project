#include <_gmp_const.h>

#include "./hlsled.hpp"
#include "./piyo.hpp"
#include <iostream>

hoge call(hoge i)
{
  hoge o;
  HlsLED(i, o);
  return o;
}

int main(int argc, char **argv)
{
  hoge o;
  if (call(0) != hoge(7)) {
    std::cout << "call(0) != hoge(7)" << std::endl;
    return 1;
  }
  if (call(2) != hoge(5)) {
    std::cout << "call(2) != hoge(7)" << std::endl;
    return 1;
  }
  if (call(4) != hoge(3)) {
    std::cout << "call(4) != hoge(3)" << std::endl;
    return 1;
  }
    if (call(7) != hoge(0)) {
    std::cout << "call(7) != hoge(0)" << std::endl;
    return 1;
  }
  return 0;
}
