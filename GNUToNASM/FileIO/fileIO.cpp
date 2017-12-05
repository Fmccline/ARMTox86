#include "fileIO.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

std::string Fileinout::readfromfile(std::string textfile)
{
  std::ifstream infile(textfile);
  if (infile.is_open())
	{
		std::stringstream buffer;
		buffer << infile.rdbuf();
		infile.close();
		return buffer.str();
	}
  else
  {
    std::cout << "Unable to open file";
    return "";
  }
}

void Fileinout::writetofile(std::string textfileout, std::string output)
{
  std::ofstream convertdata;
  convertdata.open(textfileout);
  convertdata<<output;
  convertdata.close();

}
