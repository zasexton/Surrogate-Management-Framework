#pragma once
#include <Eigen/Dense>
#include <vector>

Eigen::VectorXd vector2EigenDouble(std::vector<double> dataVector);

Eigen::VectorXi vector2EigenInteger(std::vector<int> dataVector);
