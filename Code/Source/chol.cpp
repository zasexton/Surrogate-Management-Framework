#include "chol.h"

/*
Function to return the Cholesky Decomposition
of a given dense matrix using Eigen.

Note: Cholesky Decomposition only works for
positive-definte matricies and should not be
used to determine if a system of equations has
a solution.
*/

Eigen::MatrixXd cholesky(Eigen::MatrixXd A) {
  Eigen::MatrixXd L( A.llt().matrixL() );
  return L;
}

Eigen::VectorXd fwd_sub(Eigen::MatrixXd L,Eigen::VectorXd b) {
  Eigen::VectorXd x = b*L.inverse();
  return x;
}



