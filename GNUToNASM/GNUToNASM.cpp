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

// Convert
// converts the given ARM code to x86 assembly
string GNUToNASMConverter::Convert()
{
	if (_armCode == "") return "NULL";

	_lexer = make_shared<GNULexer>(_armCode);
	_converterFactory = make_shared<ConverterFactory>(_lexer);

	string lexeme, nasmCode;
	while (true) 
	{
		lexeme = _lexer->GetNextLexeme();
		nasmCode += convertLexeme(lexeme);
		if (_lexer->IsEndOfInput())
		{
			break;
		}
	} 
	return nasmCode;
}

// convertLexeme
// creates a converter from the lexeme and returns the convertion
string GNUToNASMConverter::convertLexeme(std::string lexeme)
{
	auto converter = _converterFactory->MakeConverter(lexeme);
	if (converter)
	{
		return converter->Convert();
	}
	else
	{
		return lexeme;
	}
}

string GNUToNASMConverter::ConvertFromString(const string & armCode)
{
	_armCode = armCode;
	Convert();
}

string GNUToNASMConverter::ConvertFromFile(const string & filename)
{
	_armCode = _fileInOut.readfromfile(filename);
	Convert();
}

void GNUToNASMConverter::WriteToFile(const string & filename)
{
	_fileInOut.writetofile(filename,_armCode);
}