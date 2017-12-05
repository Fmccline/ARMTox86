#ifndef FILEIO_H_INCLUDED
#define FILEIO_H_INCLUDED

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Fileinout
{
public:
std::string readfromfile(std::string textfile);
void writetofile(std::string textfileout, std::string output);
};
#endif
