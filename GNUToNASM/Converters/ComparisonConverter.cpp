/*
	ComparisonConverter.cpp
	Authors: Frank Cline, Jason Hsi, Brandon Abbot
	6 Dec 2017

	cpp file for class that converts the cmp instruction
*/
#include "ComparisonConverter.h"
using std::shared_ptr;
using std::string;

ComparisonConverter::ComparisonConverter(shared_ptr<GNULexer> & lexer)
{
	_param0 = lexer->GetNextLexeme();
	_param1 = lexer->GetNextLexeme();
}

// Convert
// converts the ARM cmp instruction to x86
string ComparisonConverter::Convert()
{
	return "cmp " + _param0 + "," + _param1 + "\n";
}