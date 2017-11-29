/*
	Converter.h
	Frank Cline
	27 Nov 2017

	Header file for converter base class
*/

#ifndef CONVERTER_H_INCLUDED
#define CONVERTER_H_INCLUDED

#include <string>

// Converter
// base class for converter objects
class Converter
{
public:
	virtual std::string Convert() = 0;
};

#endif // CONVERTER_H_INCLUDED