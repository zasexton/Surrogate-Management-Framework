#include "utils.h"


Eigen::VectorXd vector2EigenDouble(std::vector<double> dataVector)
{
  Eigen::VectorXd dataEigen = Eigen::Map<Eigen::VectorXd,Eigen::Unaligned>(dataVector.data(),dataVector.size());
  return dataEigen;
}


Eigen::VectorXi vector2EigenInteger(std::vector<int> dataVector)
{
  Eigen::VectorXi dataEigen = Eigen::Map<Eigen::VectorXi,Eigen::Unaligned>(dataVector.data(),dataVector.size());
  return dataEigen;
}


