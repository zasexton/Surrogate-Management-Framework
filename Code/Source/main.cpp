//#include <Eigen/Dense>
#include <iostream>
#include "read.h"

int main() {
  //Eigen::MatrixXd m = Eigen::MatrixXd::Random(3,3);
  //std::cout << m << std::endl;
  //std::cout << m.inverse() << std::endl;
  std::string fileString = read("test.txt");
  std::cout << fileString << std::endl;
  return 0;
}
