/*
	InstructionConverter.h
	Authors: Frank Cline, Jason Hsi, Brandon Abbot
	27 Nov 2017

	Header file for converter base class
*/

#ifndef INSTRUCTION_CONVERTER_H_INCLUDED
#define INSTRUCTION_CONVERTER_H_INCLUDED

#include <string>
#include <utility>
#include <exception>
#include "Converter.h"

// InstructionConverter
// base class for instruction converter objects
class InstructionConverter : public Converter
{
public:
	virtual std::pair<std::string,std::string> GetConditionalParameters()
	{
		throw std::exception();
	}
};

#endif // INSTRUCTION_CONVERTER_H_INCLUDED