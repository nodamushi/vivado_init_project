#include "hlsled.hpp"

void HlsLED(hoge i, hoge& o)
{
  // ↓ ap_ctrl_noneを指定してるとcosimは動かないみたい
// #pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS interface s_axilite port=i
#pragma HLS stable variable=i

  o = ~i; // 1を書くとoff(初期で光らせたかったから)
}
