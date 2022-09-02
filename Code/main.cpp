#include <Eigen/Dense>
#include <iostream>

int main() {
  Eigen::MatrixXd m = Eigen::MatrixXd::Random(3,3);
  std::cout << m << std::endl;
  std::cout << m.inverse() << std::endl;
  std::cout << "nothing" << std::endl;
  return 0;
}
