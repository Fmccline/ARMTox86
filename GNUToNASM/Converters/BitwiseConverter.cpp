/*
	BranchConverter.cpp
	Authors: Frank Cline, Jason Hsi, Brandon Abbot
	04 Dec 2017

	cpp file for class for bitwise shift instructions
	MADE BY JASON
*/

#include "BitwiseConverter.h"

BitwiseConverter::BitwiseConverter(std::shared_ptr<GNULexer>& lexer, std::string instruction)
{
	_lexer = lexer;
	_instruction = instruction;
	_param0 = lexer->GetNextLexeme();
}

std::string BitwiseConverter::Convert()
{
	if (_instruction == "lsl")
	{
		_instruction = "shl";
	}
	else if (_instruction == "lsr")
	{
		_instruction = "shr";
	}
	else if (_instruction == "asr")
	{
		_instruction = "sar";
	}
	return _instruction + " " + _param0 + "\n";
}
