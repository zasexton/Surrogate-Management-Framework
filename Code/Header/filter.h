#pragma once
#include <Eigen/Dense>

struct filter
{
  public:
    Eigen::MatrixXd x;
    Eigen::VectorXd y;
    Eigen::VectorXd h;
}

