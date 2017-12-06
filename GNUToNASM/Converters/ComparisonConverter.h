/*
	ComparisonConverter.h
	Authors: Frank Cline, Jason Hsi, Brandon Abbot
	6 Dec 2017

	header file for class that converts the cmp instruction
*/

#ifndef CMP_CONVERTER_H_INCLUDED
#define CMP_CONVERTER_H_INCLUDED

#include "Converter.h"
#include "../Lexer/GNULexer.h"

#include <memory>
#include <string>

class ComparisonConverter : public Converter
{
private:
	std::string _param0, _param1;
public:
	ComparisonConverter(std::shared_ptr<GNULexer> & lexer);
	std::string Convert() override;
};

#endif // CMP_CONVERTER_H_INCLUDED