#include "IO_helper.h"

void writeMatrix2File(std::string filename,Eigen::MatrixXd matrix){
  const static Eigen::IOFormat CSVFormat(Eigen::StreamPrecision, Eigen::DontAlignCols, ", ", "\n");
  std::ofstream file(filename.c_str());
  if (file.is_open())
  {
    file << matrix.format(CSVFormat);
    file.close();
  }
}

Eigen::MatrixXd readFile2Matrix(std::string filename){
  std::ifstream file(filename.c_str());
  std::string line;
  std::vector<double> values;
  int row = 0;
  if (file.is_open())
  {
    while (std::getline(file,line))
    {
      std::stringstream rowStream(line);
      std::string cell;
      while (std::getline(rowStream,cell,','))
      {
        values.push_back(std::stod(cell));
      }
      ++row;
    }
  }
  return Eigen::Map<const Eigen::Matrix<typename Eigen::MatrixXd::Scalar, Eigen::MatrixXd::RowsAtCompileTime, Eigen::MatrixXd::ColsAtCompileTime, Eigen::RowMajor>>(values.data(), row, values.size()/row);
}

void writeVector2File(std::string filename,Eigen::VectorXd vector){
  const static Eigen::IOFormat CSVFormat(Eigen::StreamPrecision, Eigen::DontAlignCols, ", ", "\n");
  std::ofstream file(filename.c_str());
  if (file.is_open())
  {
    file << vector.format(CSVFormat);
    file.close();
  }
}

Eigen::VectorXi readFile2IntegerVector(std::string filename){
  std::ifstream file(filename.c_str());
  std::string line;
  std::vector<int> values;
  int row = 0;
  if (file.is_open())
  {
    while (std::getline(file,line))
    {
      std::stringstream rowStream(line);
      std::string cell;
      while (std::getline(rowStream,cell,','))
      {
        values.push_back(std::stoi(cell));
      }
      ++row;
    }
  }
  return vector2EigenInteger(values);
}

Eigen::VectorXd readFile2DoubleVector(std::string filename){
  std::ifstream file(filename.c_str());
  std::string line;
  std::vector<double> values;
  int row = 0;
  if (file.is_open())
  {
    while (std::getline(file,line))
    {
      std::stringstream rowStream(line);
      std::string cell;
      while (std::getline(rowStream,cell,','))
      {
        values.push_back(std::stod(cell));
      }
      ++row;
    }
  }
  return vector2EigenDouble(values);
}

