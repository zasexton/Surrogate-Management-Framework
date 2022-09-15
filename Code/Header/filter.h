#pragma once
#include <Eigen/Dense>
#include <math>

struct filter
{
  public:
    Eigen::MatrixXd x;
    Eigen::VectorXd y;
    Eigen::VectorXd h;
}

filter readFilterFromFile(std::string filenameXComponent,std::string filenameYComponent, std::string filenameHComponent);

void writeFilter2File(filter filterObject, std::string filenameXComponent,std::string filenameYComponent, std::string filenameHComponent);
