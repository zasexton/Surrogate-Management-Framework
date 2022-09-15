#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

std::string read(const char* filename);

std::string getLine(std::string fileContent, std::string searchTerm);

std::vector<double> read2Double(std::string dataLine);

std::vector<int> read2Integer(std::string dataLine);

//std::string getLineByNumber(std::string fileContent, int lineNumber);
