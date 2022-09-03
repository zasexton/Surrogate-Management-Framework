#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

void writeMatrix2File(std::string filename,Eigen::MatrixXd matrix);

Eigen::MatrixXd readFile2Matrix(std::string filename);
