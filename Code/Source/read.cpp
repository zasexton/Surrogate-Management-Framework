#include "read.h"
/*
Function for reading in a file
to a string output.

@author: Zachary Sexton
@date:   9-1-22
*/
std::string read(const char* filename) {
  std::ifstream file;
  file.open(filename);
  std::stringstream fileBuffer;
  fileBuffer << file.rdbuf();
  std::string fileContent = fileBuffer.str();
  return fileContent;
}
