#include "read.h"
#include <iostream>

int main() {
  std::string fileString = read("test.txt");
  std::string data       = getLine(fileString,"START");
  std::cout << "File Contents:\n\n" << std::endl;
  std::cout << fileString << std::endl;
  std::cout << "\n\n" << std::endl;
  std::cout << "START LINE DATA\n\n" << std::endl;
  std::cout << data << std::endl;
  return 0;
}
