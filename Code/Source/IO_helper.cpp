void writeMatrix2File(std::string filename,Eigen::MatrixXd matrix){
  std::ofstream file(filename.c_str());
  file << matrix.format(Eigen::CSVFormat);
}

Eigen::MatrixXd readFile2Matrix(std::string){
  //read into eigen format
}
