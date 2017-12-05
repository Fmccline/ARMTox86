/*
	ArithmeticConverter.cpp
	Authors: Frank Cline, Jason Hsi, Brandon Abbot
	28 Nov 2017

	cpp file for class for arithmetic instructions
*/
#include "ArithmeticConverter.h"
using std::shared_ptr;
using std::string;
using std::make_pair;
using std::pair;

ArithmeticConverter::ArithmeticConverter(shared_ptr<GNULexer> & lexer, string instruction)
{
	_instruction = instruction;
	_lexer = lexer;
	_param0 = _lexer->GetNextLexeme();
	_param1 = _lexer->GetNextLexeme();
	_param2 = _lexer->GetNextLexeme();
}

// Convert
// converts the ARM add instruction to x86
string ArithmeticConverter::Convert()
{
	string convertion;
	// special case for multiplication
	if (_instruction == "mul")
	{
		_instruction = "imul";
	}
	if (_param0 != _param1)
	{
		convertion += "mov " + _param0 + "," + _param1 + "\n";
	}
	convertion += _instruction + " " + _param0 + "," + _param2 + "\n";

	return convertion;
}