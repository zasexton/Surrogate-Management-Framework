#include "settings.h"

int getPhaseFromString(std::string fileContent)
{
  int phase;

  size_t startFound     = fileContent.find("START");
  size_t lhsFound       = fileContent.find("LHS");
  size_t searchFound    = fileContent.find("SEARCH");
  size_t pollFeasFound  = fileContent.find("POLL-FEAS");
  size_t pollInfFound   = fileContent.find("POLL-INF");
  size_t restartFound   = fileContent.find("RESTART");

  if (startFound != std::string::npos)
  {
    phase = 0;
  }
  else if (lhsFound != std::string::npos)
  {
    phase = 1;
  }
  else if (searchFound != std::string::npos)
  {
    phase = 2;
  }
  else if (pollFeasFound != std::string::npos)
  {
    phase = 3;
  }
  else if (pollInfFound != std::string::npos)
  {
    phase = 4;
  }
  else if (restartFound != std::string::npos)
  {
    phase = 5;
  }
  else
  {
    std::cout << "Phase option required!" << std::endl;
    std::cout << "Phase options available: " << std::endl;
    std::cout << "START, LHS, SEARCH, POLL-FEAS, POLL-INF, RESTART" << std::endl;
    throw std::runtime_error("Unknown phase option! \n");
  }

  return phase;
}


std::string getLine(std::string fileContent, std::string searchTerm, int pos)
{
  //not finished yet!!
}
