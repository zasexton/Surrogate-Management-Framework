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


/*

 Function for getting the line of data/parameter values
 following the specified search term that is given. New
 lines are delimited by the new line indication "\n"

 Parameters
 ----------
           fileContent : std::string
                         This is a string representation of
                         a parameter file that has been read.

           searchTerm  : std::string
                         This is the search term that will be
                         queried.

  Returns
  -------
           dataLine : std::string
                      A string containing the line which follows
                      the given search string. This string has
                      not been cleaned/sanitized and will be exactly
                      as it is in the original parameter file.
                      If the searchTerm could not be found or
                      no line follows the given searchTerm then
                      the dataLine will return an empty string.

*/

std::string getLine(std::string fileContent, std::string searchTerm)
{
  size_t searchTermStart = fileContent.find(searchTerm);
  std::string = dataLine;
  if (searchTermStart != std::npos)
  {
    size_t endSearchTerm = FileContent.find("\n",searchTermStart);
    size_t startDataLine = endSearchTerm + 1;
    size_t endDataLine   = FileContent.find("\n",startDataLine) - 1;
    dataLine             = FileContent.substr(startDataLine,endDataLine);
  }
  return dataLine;
}

