/*
	PushAndPopConverter.h
	Authors: Frank Cline, Jason Hsi, Brandon Abbot
	30 Nov 2017

	cpp file for class that converts the GNU push and pop instructions
*/
#include "PushAndPopConverter.h"
using std::shared_ptr;
using std::string;
using std::vector;
using std::reverse;

PushAndPopConverter::PushAndPopConverter(shared_ptr<GNULexer> & lexer, string instruction)
{
	_instruction = instruction;
	_lexer = lexer;
	setParameters();
}

// Convert
// converts an ARM push or pop instruction to an x86 instruction
string PushAndPopConverter::Convert()
{
	string convertion = "";
	auto begin = _parameters.begin();
	auto end = _parameters.end();
	// Reverse the parameters if pop instruction
	if (_instruction == "pop")
	{
		reverse(begin,end);
	}

	for (auto iter = begin; iter != end; ++iter)
	{
		convertion += _instruction + " " + *iter + "\n";
	}
	return convertion;
}

// setParameters
// sets a list of paramters that will be each be called with push or pop
void PushAndPopConverter::setParameters()
{
	string lexeme = _lexer->GetNextLexeme();
	string parameter;
	bool moreParameters = true;

	if (lexeme[0] == '{')
	{
		parameter = lexeme.substr(1,lexeme.length()-1);
	}
	else if (lexeme[lexeme.length()-1] == '}')
	{
		parameter = lexeme.substr(0,lexeme.length()-1);
		moreParameters = false;
	}
	else
	{
		parameter = lexeme;
	}
	_parameters.push_back(parameter);

	if (moreParameters)
	{
		setParameters();
	}
}