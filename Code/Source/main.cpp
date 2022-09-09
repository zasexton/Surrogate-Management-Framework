//#include <Eigen/Dense>
#include <iostream>
#include <string>
//#include "settings.h"
#include "read.h"
//#include "IO_helper.h"

int main() {
  //Eigen::MatrixXd m = Eigen::MatrixXd::Random(3,3);
  //std::cout << m << std::endl;
  //std::cout << m.inverse() << std::endl;
  //std::string fileString = read("test.txt");
  //std::cout << fileString << std::endl;
  //writeMatrix2File("text.csv",m);
  //Eigen::MatrixXd A = readFile2Matrix("text.csv");
  //std::cout << " " <<std::endl;
  //std::cout << A << std::endl;
  std::string fileContent="\nSTART\nother information\n";
  //int num = getPhaseFromString(fileContent);
  std::string data = getLine(fileContent,"START");
  std::cout << data << std::endl;
  return 0;
}
