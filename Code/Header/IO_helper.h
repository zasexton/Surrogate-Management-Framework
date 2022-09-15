#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

#include "utils.h"

void writeMatrix2File(std::string filename,Eigen::MatrixXd matrix);

Eigen::MatrixXd readFile2Matrix(std::string filename);

void writeVector2File(std::string filename,Eigen::VectorXd vector);

Eigen::VectorXi readFile2IntegerVector(std::string filename);

Eigen::VectorXd readFile2DoubleVector(std::string filename);
