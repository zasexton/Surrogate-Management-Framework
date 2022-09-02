struct model {
  public:
    int numPts,dim,theta_dim;
    Eigen::MatrixXd x0,L;
    Eigen::VectorXd y0,theta;
    Eigen::VectorId theta_index;
};

struct settings {
  public:
    int phase = -1;
    int dim = 0;
    int theta_dim = 0;
    int ndiv = 0;
    int numPtsSurrogateSearch = 4;
    //not finished yet
}
