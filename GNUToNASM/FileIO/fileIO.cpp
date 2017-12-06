#include "fileIO.h"
#include <fstream>
#include <sstream>
#include <string>

std::string Fileinout::readfromfile(const std::string & textfile)
{
  std::ifstream infile(textfile);
  if (infile.is_open())
	{
    std::string fileContents, line;
    while (std::getline(infile,line))
    {
      fileContents += line + '\n';
    }
		infile.close();
		return fileContents;
	}
  
  return "NULL";
}

void Fileinout::writetofile(const std::string & textfileout, const std::string & output)
{
  std::ofstream convertdata(textfileout);
  if (convertdata.is_open())
  {
    convertdata << output;
    convertdata.close();
  }
}
