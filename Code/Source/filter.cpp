#include "filter.h"

filter readFilterFromFile(std::string filenameXComponent,std::string filenameYComponent, std::string filenameHComponent)
{
  filter filterObject;
  filterObject.x = readFile2Matrix(filenameXComponent);
  filterObject.y = readFile2DoubleVector(filenameYComponent);
  filterObject.h = readFile2DoubleVector(filenameHComponent);
  return filterObject;
}

void writeFilter2File(filter filterObject, std::string filenameXComponent,std::string filenameYComponent, std::string filenameHComponent)
{
  writeMatrix2File(filenameXComponent, filterObject.x);
  writeVector2File(filenameYComponent, filterObject.y);
  writeVector2File(filenameHComponent, filterObject.h);
}
