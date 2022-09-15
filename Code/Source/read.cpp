#include "read.h"
/*
Function for reading in a file
to a string output.

@author: Zachary Sexton
@date:   9-1-22
*/


/*

 Function for reading a file into a
 text string.

 Parameters
 ----------

          filename : const char
                    The path to a file.

 Returns
 -------

          fileContent : string
                    The file contents represented
                    as one string object.

*/
std::string read(const char* filename) {
  std::ifstream file;
  file.open(filename);
  std::stringstream fileBuffer;
  fileBuffer << file.rdbuf();
  std::string fileContent = fileBuffer.str();
  return fileContent;
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
  std::string dataLine;
  if (searchTermStart != std::string::npos)
  {
    size_t endSearchTerm = fileContent.find("\n",searchTermStart);
    size_t startDataLine = endSearchTerm + 1;
    size_t endDataLine   = fileContent.find("\n",startDataLine) - 1;
    dataLine             = fileContent.substr(startDataLine,endDataLine);
  }
  return dataLine;
}

/*

 Function that takes a string of numeric
 data seperated by spaces and returns a
 vector object of numeric double elements.

 Parameters
 ----------

           dataString : string
                      string containing numeric data.
                      This string should be clean i.e.
                      there should be no characters
                      other than numbers, periods, and
                      spaces. The string should also
                      not begin or end with a space
                      character.

 Returns
 -------

           data : std::vector<double>
                      vector of double elements

*/

std::vector<double> read2Double(std::string dataString)
{
  std::stringstream dataStream(dataString);
  std::vector<double> data;
  double element;

  while (dataStream >> element)
  {
    data.push_back(element);
  }
  return data;
}

/*

 Function that takes a string of numeric
 data seperated by spaces and returns a
 vector object of numeric integer elements.

 Parameters
 ----------

           dataString : string
                      string containing numeric data.
                      This string should be clean i.e.
                      there should be no characters
                      other than numbers, periods, and
                      spaces. The string should also
                      not begin or end with a space
                      character.

 Returns
 -------

           data : std::vector<int>
                      vector of integer elements

*/


std::vector<int> read2Integer(std::string dataString)
{
  std::stringstream dataStream(dataString);
  std::vector<int> data;
  int element;

  while (dataStream >> element)
  {
    data.push_back(element);
  }
  return data;
}

/*

  Function to get a specific line from
  a string containing an entire file.

  Paramters
  ---------

           fileContent : std::string
                       A string containing
                       file contents seperated
                       by newlines.

           lineNumber  : int
                       The integer of the line
                       from the file to return.
                       Line indexing begins at
                       zero.

  Returns
  -------

           line        : std::string
                       String containing the file
                       information of the specified
                       line number.

*/

//std::string getLineByNumber(std::string fileContent, int lineNumber)
//{
  // Count the number of Lines in the fileContent string
  // This is used to check if the lineNumber argument
  // is within bounds.
//  int lineCount = std::count(fileContent.begin(),fileContent.end(),'\n') + 1;
//  if (lineNumber <= lineCount)
//  {
//    TODO
//  }
//}
