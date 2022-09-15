#include "lhs.h"


//void lhs(Eigen::VectorXd lowBound, Eigen::VectorXd upperBound)
void lhs()
{
  Py_Initialize();
  PyObject * numpy = PyImport_ImportModule("numpy");
  Py_Finalize();
}
