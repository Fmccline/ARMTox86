/*
	ConditionalConverter.h
	Authors: Frank Cline, Jason Hsi, Brandon Abbot
	1 Dec 2017

	header file for class that converts conditional suffixes for ARM instructions
*/

#ifndef CONDITIONAL_CONVERTER_H_INCLUDED
#define CONDITIONAL_CONVERTER_H_INCLUDED

#include "Converter.h"
#include "../Lexer/GNULexer.h"

#include <memory>
#include <string>
#include <unordered_map>

class ConditionalConverter : public Converter
{
private:
	static int _conditionalCount;
	std::string _instruction, _conditional;
	const std::unordered_map<std::string,std::string> _CONDITIONALS;
public:
	ConditionalConverter(const std::string & conditional, std::shared_ptr<Converter> & instructionConverter);
	std::string Convert() override;
};

#endif // CONDITIONAL_CONVERTER_H_INCLUDED