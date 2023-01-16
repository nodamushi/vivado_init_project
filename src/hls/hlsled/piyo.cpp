#include <iostream>
#include <string>
#include <sstream>
#include <cxxabi.h>

void piyo(std::string s) {
  std::ostringstream ss;
  ss << " ===== PIYO <<<< " << s ;
  std::cout << ss.str() << std::endl;
}