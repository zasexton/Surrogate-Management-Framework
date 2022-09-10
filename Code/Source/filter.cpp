#include "filter.h"

filter importFilter(const char* filename, int dimension, int num_pts, Eigen::VectorXi xindex)
{
  std::string filterString = read(filename);
  Eigen::MatrixXd v;
  //working on this
}
