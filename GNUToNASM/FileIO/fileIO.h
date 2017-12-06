#ifndef FILEIO_H_INCLUDED
#define FILEIO_H_INCLUDED

#include <fstream>
#include <sstream>
#include <string>

class Fileinout
{
public:
std::string readfromfile(const std::string & textfile);
void writetofile(const std::string & textfileout, const std::string &  output);
};
#endif
