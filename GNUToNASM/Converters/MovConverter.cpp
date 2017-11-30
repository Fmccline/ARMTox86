/*
	MovConverter.cpp
	Authors: Frank Cline, Jason Hsi, Brandon Abbot
	28 Nov 2017

	cpp file for class that converts the mov instruction
*/
#include "MovConverter.h"
using std::shared_ptr;
using std::string;

MovConverter::MovConverter(shared_ptr<GNULexer> & lexer)
{
	_lexer = lexer;
	_param0 = _lexer->GetNextLexeme();
	_param1 = _lexer->GetNextLexeme();
}

// Convert
// converts the ARM mov instruction to x86
string MovConverter::Convert()
{
	return "mov " + _param0 + "," + _param1 + "\n";
}