/*
	LexemeConverter.cpp
	Authors: Frank Cline, Jason Hsi, Brandon Abbot
	29 Nov 2017

	cpp file for class that converts ARM registsers and constants to x86
*/
#include "LexemeConverter.h"
using std::string;

LexemeConverter::LexemeConverter(string lexeme)
{
	_lexeme = lexeme;
}

string LexemeConverter::Convert()
{
	if (_lexeme[0] == '#')
	{
		return convertConstant();
	}
	else if (_lexeme[0] == 'r')
	{
		return convertRegister();
	}
	else
	{
		return _lexeme;
	}
}

string LexemeConverter::convertConstant()
{
	return _lexeme.substr(1,_lexeme.length()-1);
}

string LexemeConverter::convertRegister()
{
	// TODO: Actually convert to register
	return _lexeme;
}