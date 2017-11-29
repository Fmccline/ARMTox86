/*
	PushConverter.cpp
	Authors: Frank Cline, Jason Hsi, Brandon Abbot
	28 Nov 2017

	cpp file for class that converts the GNU push instruction
*/
#include "PushConverter.h"
using std::shared_ptr;
using std::string;
using std::vector;

PushConverter::PushConverter(shared_ptr<GNULexer> & lexer)
{
	_lexer = lexer;
	setParameters();
}

string PushConverter::Convert()
{
	string convertion = "";
	for (auto iter = _parameters.begin(); iter != _parameters.end(); ++iter)
	{
		convertion += "push " + *iter + "\n";
	}
	return convertion;
}

void PushConverter::setParameters()
{
	string lexeme = _lexer->GetNextLexeme();
	string parameter;
	bool moreParameters = true;

	if (lexeme[0] == '{')
	{
		parameter = lexeme.substr(1,lexeme.length()-1);
	}
	else if (lexeme.find("}"))
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