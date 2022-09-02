#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "read_phase.h"
#include "compare_in.h"
#include "settings.h"

void read_phase(const char* filename,settings &smfSettings)
{
    std::ifstream parameterFile;
    std::string line;
    parameterFile.open(filename);

    if(parameterFile.is_open())
    {
        // File exists. Start read in loop

        while(std::getline(parameterFile,line))
        {

            // read current state of the smf loop
            if(compare_in(line,"Phase"))
            {
                std::cout<<line<<"\n";
                std::getline(parameterFile,line);

                if (compare_in(line,"START"))
                    smfSettings.phase = 0;
                else if (compare_in(line,"SEARCH"))
                    smfSettings.phase = 2;
                else if (compare_in(line,"POLL-FEAS"))
                    smfSettings.phase = 3;
                else if (compare_in(line,"POLL-INF"))
                    smfSettings.phase = 4;
                else if (compare_in(line,"LHS"))
                    smfSettings.phase = 1;
                else if (compare_in(line,"RESTART"))
                    smfSettings.phase = 5;
                else
                {
                    std::cout<<"Incorrect phase option provided \nPlease select from : LHS, Search, Poll or Restart\n";
                    throw std::runtime_error("Unknown phase option selected \n");
                }

                std::cout<<line<<"\n";

            }

            // Read dimension and target number of LHS points
            if(compare_in(line,"Dimension"))
            {
                std::cout<<line<<"\n";
                std::getline(parameterFile,line);
                smfSettings.dim = std::stoi(line);
                std::cout<<line<<"\n";
            }


            if(compare_in(line,"Number of LHS divisions"))
            {
                std::cout<<line<<"\n";
                std::getline(parameterFile,line);
                smfSettings.ndiv = std::stoi(line);
                std::cout<<line<<"\n";
            }

            // read bounds
            if(compare_in(line,"Upper bound"))
            {
                std::cout<<line<<"\n";
                std::getline(parameterFile,line);
                ReadNumbers(line,smfSettings.xupp);
                std::cout<<line<<"\n";
            }

            if(compare_in(line,"Lower bound"))
            {
                std::cout<<line<<"\n";
                std::getline(parameterFile,line);
                ReadNumbers(line,smfSettings.xlow);
                std::cout<<line<<"\n";
            }

            // Read spacing

            if(compare_in(line,"Spacing"))
            {
                std::cout<<line<<"\n";
                std::getline(parameterFile,line);
                ReadIntNumbers(line,smfSettings.spc);
                std::cout<<line<<"\n";
            }

            // Read number of points at each phase

            if(compare_in(line,"Number of lhs points"))
            {
                std::cout<<line<<"\n";
                std::getline(parameterFile,line);
                smfSettings.npts_lhs = std::stoi(line);
                std::cout<<line<<"\n";
            }

            if(compare_in(line,"Number of search points"))
            {
                std::cout<<line<<"\n";
                std::getline(parameterFile,line);
                smfSettings.npts_search = std::stoi(line);
                std::cout<<line<<"\n";            }

            if(compare_in(line,"Number of feasible poll points"))
            {
                std::cout<<line<<"\n";
                std::getline(parameterFile,line);
                smfSettings.npts_pollfeas = std::stoi(line);
                std::cout<<line<<"\n";
            }

            if(compare_in(line,"Number of infeasible poll points"))
            {
                std::cout<<line<<"\n";
                std::getline(parameterFile,line);
                smfSettings.npts_pollinf = std::stoi(line);
                std::cout<<line<<"\n";
            }

            // Read in number of search and poll stages executed till now
            if(compare_in(line,"Number of search stages"))
            {
                std::cout<<line<<"\n";
                std::getline(parameterFile,line);
                smfSettings.nstage_search = std::stoi(line);
                std::cout<<line<<"\n";
            }

            if(compare_in(line,"Number of feasible poll stages"))
            {
                std::cout<<line<<"\n";
                std::getline(parameterFile,line);
                smfSettings.nstage_pollfeas = std::stoi(line);
                std::cout<<line<<"\n";
            }


            if(compare_in(line,"Number of infeasible poll stages"))
            {
                std::cout<<line<<"\n";
                std::getline(parameterFile,line);
                smfSettings.nstage_pollinf = std::stoi(line);
                std::cout<<line<<"\n";
            }

            // Read in number of successful search and poll stages till now

            if(compare_in(line,"Number of successful search stages"))
            {
                std::cout<<line<<"\n";
                std::getline(parameterFile,line);
                smfSettings.succ_search = std::stoi(line);
                std::cout<<line<<"\n";
            }

            if(compare_in(line,"Number of successful feasible poll stages"))
            {
                std::cout<<line<<"\n";
                std::getline(parameterFile,line);
                smfSettings.succ_pollfeas = std::stoi(line);
                std::cout<<line<<"\n";
            }

            if(compare_in(line,"Number of successful infeasible poll stages"))
            {
                std::cout<<line<<"\n";
                std::getline(parameterFile,line);
                smfSettings.succ_pollinf = std::stoi(line);
                std::cout<<line<<"\n";
            }

            // Read in initial guess for hyper-parameter values

            if(compare_in(line,"Kriging theta"))
            {
                std::cout<<line<<"\n";
                std::getline(parameterFile,line);
                ReadNumbers(line,smfSettings.theta);
                std::cout<<line<<"\n";
            }

            // Read in hyper-parameter bounds

            if(compare_in(line,"Kriging theta upper bound"))
            {
                std::cout<<line<<"\n";
                std::getline(parameterFile,line);
                ReadNumbers(line,smfSettings.thupp);
                std::cout<<line<<"\n";
            }


            if(compare_in(line,"Kriging theta lower bound"))
            {
                std::cout<<line<<"\n";
                std::getline(parameterFile,line);
                ReadNumbers(line,smfSettings.thlow);
                std::cout<<line<<"\n";
            }


            // Read in pointwise stage history

            if(compare_in(line,"Pointwise history"))
            {
                std::cout<<line<<"\n";
                std::getline(parameterFile,line);
                // Assume a maximum number of 5000 points stored in history
                // std::size_t len_hist = line.copy(smfSettings.hist_id,5000);
                smfSettings.pt_hist = line ;
                std::cout<<line<<"\n" ;
            }

            if(compare_in(line,"IDs of points that were successful"))
            {
                std::cout<<line<<"\n";
                std::getline(parameterFile,line);
                ReadIntNumbers(line,smfSettings.succ_pts_id);

                std::cout<<line<<"\n";
            }

            if(compare_in(line,"Function values reduced"))
            {
                std::cout<<line<<"\n";
                std::getline(parameterFile,line);
                ReadNumbers(line,smfSettings.succ_delta);
                std::cout<<line<<"\n";
            }
        }
    }
    else
    {
        std::cout<<"No phase file present \n ";
        // Return error
        throw std::runtime_error("Need a phase file for execution \n");
   }

    parameterFile.close();
}
