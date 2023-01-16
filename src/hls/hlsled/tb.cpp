#include "./hlsled.hpp"
#include "./piyo.hpp"
#include <gtest/gtest.h>
#include <iostream>

void call(hoge i, hoge& o)
{
  HlsLED(i, o);
}

TEST(test, t1){
  hoge o;
  call(0, o);
  ASSERT_EQ(o, hoge(7));
}

TEST(test, t2) {
  hoge o;
  call(2, o);
  ASSERT_EQ(o, hoge(5));
}
TEST(test, t3) {
  hoge o;
  call(4, o);
  ASSERT_EQ(o, hoge(3));
}
TEST(test, t4) {
  hoge o;
  call(7, o);
  ASSERT_EQ(o, hoge(0));
}

int main(int argc, char **argv)
{
  piyo("hoge");
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
