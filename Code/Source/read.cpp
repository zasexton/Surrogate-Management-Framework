#include "read.h"
/*
Function for reading in a file
to a string output.
*/
std::string read(const char* filename) {
  std::ifstream file;
  file.open(filename);
  std::stringstream fileBuffer;
  fileBuffer << file.rdbuf();
  std::string fileContent = fileBuffer.str();
  return fileContent;
}
