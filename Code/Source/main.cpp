//#include <Eigen/Dense>
#include <iostream>
//#include <string>
//#include <vector>
#include "settings.h"
//#include "read.h"
//#include "IO_helper.h"
#include "lhs.h"


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
  //std::string fileContent="\nSTART\nUpper bound\n3.0 2.0 1.0\nLower bound\n2.3 -1.0 -2.0\n";
  //int num = getPhaseFromString(fileContent);
  //std::string dataString = getLine(fileContent,"Dimension");
  //std::vector<int> data = read2Integer(dataString);
  //settings data = createSettingsFromFile("test.txt");
  //std::cout << data.xupp << std::endl;
  //std::cout << data.xlow << std::endl;
  lhs();
  return 0;
}
