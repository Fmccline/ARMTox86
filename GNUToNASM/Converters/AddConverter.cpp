/*
	AddConverter.cpp
	Authors: Frank Cline, Jason Hsi, Brandon Abbot
	28 Nov 2017

	cpp file for class that converts the add instruction
*/
#include "AddConverter.h"
using std::shared_ptr;
using std::string;

AddConverter::AddConverter(shared_ptr<GNULexer> & lexer)
{
	_lexer = lexer;
	_param0 = _lexer->GetNextLexeme();
	_param1 = _lexer->GetNextLexeme();
	_param2 = _lexer->GetNextLexeme();
}

// Convert
// converts the ARM add instruction to x86
string AddConverter::Convert()
{
	string convertion;

	if (_param0 != _param1)
	{
		convertion += "mov " + _param0 + "," + _param1 + "\n";
	}
	convertion += "add " + _param0 + "," + _param2 + "\n";

	return convertion;
}