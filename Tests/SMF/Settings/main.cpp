#include <iostream>
#include <string>
#include "settings.h"

int main() {
  std::string fileContent="\nSTART\nother information";
  int num = getPhaseFromString(fileContent);
  std::cout << "Phase found from string is: " << num << std::endl;
  return 0;
}
