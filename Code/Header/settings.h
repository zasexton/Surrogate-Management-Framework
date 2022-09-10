#pragma once
#include <Eigen/Dense>
#include <string>
#include <iostream>
#include "read.h"
#include <vector>

struct settings {

  public:
    // if the value of phase is :
    // 0 --- START
    // 1 --- LHS
    // 2 --- SEARCH
    // 3 --- POLL
    // 4 --- RESTART (SEARCH/POLL STATS NOT USED IN THIS SETTING)
    int phase = -1;

    // Define Dimensions ---------------------

    int design_dimensions=0 ;
    int hyper_parameter_dimensions=0;
    int ndiv=0;

    // ----------------------------------

    // INTERNAL PARAMETERS --------------

    int npts_surr_search = 4;
    Eigen::VectorXi spc;
    Eigen::VectorXd xupp, xlow;
    Eigen::VectorXd hyper_parameters;

    Eigen::VectorXd thlow, thupp;
    Eigen::VectorXi th_index, xlog_index ;

    // STATISTICS VARIABLES

    // History of point phase

    std::string pt_hist ;

    int npts_lhs = 0 ;
    int npts_search = 0 ;
    int npts_pollfeas = 0 ;
    int npts_pollinf = 0 ;

    int npts_tot = 0 ;

    int nstage_search = 0 ;
    int nstage_pollfeas = 0 ;
    int nstage_pollinf = 0 ;

    int succ_search = 0 ;
    int succ_pollfeas = 0 ;
    int succ_pollinf = 0 ;


    // History of successful improvement points
    Eigen::VectorXi successful_pts_id ;
    Eigen::VectorXd successful_delta ;

};

int getPhaseFromString(std::string fileContent);

settings createSettingsFromFile(const char* filename);
