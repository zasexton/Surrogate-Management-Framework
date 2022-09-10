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


Eigen::VectorXd vector2EigenDouble(std::vector<double> dataVector)
{
  Eigen::VectorXd dataEigen = Eigen::Map<Eigen::VectorXd,Eigen::Unaligned>(dataVector.data(),dataVector.size());
  return dataEigen;
}


Eigen::VectorXi vector2EigenInteger(std::vector<int> dataVector)
{
  Eigen::VectorXi dataEigen = Eigen::Map<Eigen::VectorXi,Eigen::Unaligned>(dataVector.data(),dataVector.size());
  return dataEigen;
}


settings createSettingsFromFile(const char* filename)
{
  std::string fileContent = read(filename);
  std::string dataLine;
  settings settingsObject;

  int phase = getPhaseFromString(fileContent);

  dataLine  = getLine(fileContent,"Dimension");
  if (dataLine.size() > 0)
  {
    std::vector<int> dimension       = read2Integer(dataLine);
    settingsObject.design_dimensions = dimension[0];
  }

  dataLine  = getLine(fileContent,"Number of LHS divisions");
  if (dataLine.size() > 0)
  {
    std::vector<int> lhsDivisions  = read2Integer(dataLine);
    settingsObject.ndiv            = lhsDivisions[0];
  }

  dataLine  = getLine(fileContent,"Upper bound");
  if (dataLine.size() > 0)
  {
    std::vector<double> upperBound = read2Double(dataLine);
    Eigen::VectorXd xupp           = vector2EigenDouble(upperBound);
    settingsObject.xupp            = xupp;
  }

  dataLine  = getLine(fileContent,"Lower bound");
  if (dataLine.size() > 0)
  {
    std::vector<double> lowerBound = read2Double(dataLine);
    Eigen::VectorXd xlow           = vector2EigenDouble(lowerBound);
    settingsObject.xlow            = xlow;
  }

  dataLine  = getLine(fileContent,"Spacing");
  if (dataLine.size() > 0)
  {
    std::vector<int> spacing       = read2Integer(dataLine);
    Eigen::VectorXi spacingEigen   = vector2EigenInteger(spacing);
    settingsObject.spc             = spacingEigen;
  }

  dataLine  = getLine(fileContent,"Number of lhs points");
  if (dataLine.size() > 0)
  {
    std::vector<int> numberLHSPoints = read2Integer(dataLine);
    settingsObject.npts_lhs          = numberLHSPoints[0];
  }

  dataLine  = getLine(fileContent,"Number of search points");
  if (dataLine.size() > 0)
  {
    std::vector<int> numberSearchPoints = read2Integer(dataLine);
    settingsObject.npts_search          = numberSearchPoints[0];
  }

  dataLine  = getLine(fileContent,"Number of feasible poll points");
  if (dataLine.size() > 0)
  {
    std::vector<int> numberFeasiblePollPts = read2Integer(dataLine);
    settingsObject.npts_pollfeas        = numberFeasiblePollPts[0];
  }

  dataLine  = getLine(fileContent,"Number of infeasible poll points");
  if (dataLine.size() > 0)
  {
    std::vector<int> numberInfeasiblePollPts = read2Integer(dataLine);
    settingsObject.npts_pollinf              = numberInfeasiblePollPts[0];
  }

  dataLine  = getLine(fileContent,"Number of search stages");
  if (dataLine.size() > 0)
  {
    std::vector<int> numberSearchStages       = read2Integer(dataLine);
    settingsObject.nstage_search              = numberSearchStages[0];
  }

  dataLine  = getLine(fileContent,"Number of feasible poll stages");
  if (dataLine.size() > 0)
  {
    std::vector<int> numberFeasiblePollStages = read2Integer(dataLine);
    settingsObject.nstage_pollfeas             = numberFeasiblePollStages[0];
  }

  dataLine  = getLine(fileContent,"Number of infeasible poll stages");
  if (dataLine.size() > 0)
  {
    std::vector<int> numberInfeasiblePollStages = read2Integer(dataLine);
    settingsObject.nstage_pollinf               = numberInfeasiblePollStages[0];
  }

  dataLine  = getLine(fileContent,"Number of successful search stages");
  if (dataLine.size() > 0)
  {
    std::vector<int> numberSuccessfulSearchStages = read2Integer(dataLine);
    settingsObject.succ_search                    = numberSuccessfulSearchStages[0];
  }

  dataLine  = getLine(fileContent,"Number of successful feasible poll stages");
  if (dataLine.size() > 0)
  {
    std::vector<int> numberSuccessfulFeasiblePollStages = read2Integer(dataLine);
    settingsObject.succ_pollfeas                        = numberSuccessfulFeasiblePollStages[0];
  }

  dataLine  = getLine(fileContent,"Number of successful infeasible poll stages");
  if (dataLine.size() > 0)
  {
    std::vector<int> numberSuccessfulInfeasiblePollStages = read2Integer(dataLine);
    settingsObject.succ_pollinf                           = numberSuccessfulInfeasiblePollStages[0];
  }

  dataLine  = getLine(fileContent,"Initial hyper-parameter values");
  if (dataLine.size() > 0)
  {
    std::vector<double> hyperparameterValues      = read2Double(dataLine);
    Eigen::VectorXd hyperparameterValuesEigen  = vector2EigenDouble(hyperparameterValues);
    settingsObject.hyper_parameters            = hyperparameterValuesEigen;
  }

  dataLine  = getLine(fileContent,"Initial hyper-parameter lower bound");
  if (dataLine.size() > 0)
  {
    std::vector<double> hyperparameterLowerBound          = read2Double(dataLine);
    Eigen::VectorXd hyperparameterLowerBoundEigen      = vector2EigenDouble(hyperparameterLowerBound);
    settingsObject.thlow                               = hyperparameterLowerBoundEigen;
  }

  dataLine  = getLine(fileContent,"Initial hyper-parameter upper bound");
  if (dataLine.size() > 0)
  {
    std::vector<double> hyperparameterUpperBound          = read2Double(dataLine);
    Eigen::VectorXd hyperparameterUpperBoundEigen      = vector2EigenDouble(hyperparameterUpperBound);
    settingsObject.thupp                               = hyperparameterUpperBoundEigen;
  }

  dataLine  = getLine(fileContent,"IDs of points that were successful");
  if (dataLine.size() > 0)
  {
    std::vector<int> successfulPtIds                   = read2Integer(dataLine);
    Eigen::VectorXi successfulPtIdsEigen               = vector2EigenInteger(successfulPtIds);
    settingsObject.successful_pts_id                   = successfulPtIdsEigen;
  }

  dataLine  = getLine(fileContent,"Function values returned");
  if (dataLine.size() > 0)
  {
    std::vector<double> successfulDelta                = read2Double(dataLine);
    Eigen::VectorXd successfulDeltaEigen               = vector2EigenDouble(successfulDelta);
    settingsObject.successful_delta                    = successfulDeltaEigen;
  }

  return settingsObject;
}
