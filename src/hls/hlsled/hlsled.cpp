#include "hlsled.hpp"

void HlsLED(hoge i, hoge& o)
{
  // ↓ AXI Lite + ap_ctrl_noneを指定してるとcosimは動かないみたい
  // cosim を試す場合はコメントアウトしてください。
#pragma HLS interface ap_ctrl_none port=return
#pragma HLS interface s_axilite port=i
#pragma HLS stable variable=i

  o = ~i; // 1を書くとoff(初期で光らせたかったから)
}
