#include "chol.h"
#include <Eigen/Dense>
#include <iostream>

int main() {
  Eigen::MatrixXd m = Eigen::MatrixXd::Random(3,3);
  std::cout << m << std::endl;
  Eigen::MatrixXd L = cholesky(m);
  std::cout << L << std::endl;
  return 0;
}
