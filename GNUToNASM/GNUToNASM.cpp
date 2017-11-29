/*
	GNUToNASM.cpp
	Authors: Frank Cline, Jason Hsi, Brandon Abbot
	27 Nov 2017

	cpp file for ARM to x86 converter
*/
#include "GNUToNASM.h"
using std::shared_ptr;
using std::make_shared;
using std::string;

GNUToNASMConverter::GNUToNASMConverter(string gnuCode)
{
	_lexer = make_shared<GNULexer>(gnuCode);
	_instructionFactory = make_shared<InstructionFactory>(_lexer);
}

string GNUToNASMConverter::Convert()
{
	string lexeme, nasmCode;
	while (true) 
	{
		lexeme = _lexer->GetNextLexeme();
		nasmCode += ".." + convertLexeme(lexeme);
		if (_lexer->IsEndOfInput())
		{
			break;
		}
	} 
	return nasmCode;
}

string GNUToNASMConverter::convertLexeme(std::string lexeme)
{
	auto instructionConverter = _instructionFactory->MakeInstructionConverter(lexeme);
	if (instructionConverter)
	{
		return instructionConverter->Convert();
	}
	else
	{
		return lexeme;
	}
}