#pragma once
#include <Eigen/Dense>

Eigen::MatrixXd cholesky(Eigen::MatrixXd A);

Eigen::VectorXd fwd_sub(Eigen::MatrixXd L,Eigen::VectorXd b);
