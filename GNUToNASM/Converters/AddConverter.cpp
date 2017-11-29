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

string AddConverter::Convert()
{
	string convertion;
	if (_param2[0] == '#')
	{
		_param2 = _param2.substr(1,_param2.length());
	}
	if (_param0 != _param1)
	{
		convertion += "mov " + _param0 + "," + _param1;
	}
	convertion += "add " + _param0 + "," + _param2 + "\n";

	return convertion;
}