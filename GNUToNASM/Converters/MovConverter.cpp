/*
	MovConverter.cpp
	Frank Cline
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

string MovConverter::Convert()
{
	if (_param1[0] == '#')
	{
		_param1 = _param1.substr(1,_param1.length());
	}
	return "mov " + _param0 + "," + _param1 + "\n";
}