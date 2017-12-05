/*
	ConverterFactory.cpp
	Authors: Frank Cline, Jason Hsi, Brandon Abbot
	28 Nov 2017

	cpp file for factory that creates instruction converters
*/

#include "stdafx.h"

#include "ConverterFactory.h"
using std::shared_ptr;
using std::make_shared;
using std::string;
using std::move;


ConverterFactory::ConverterFactory(shared_ptr<GNULexer> & lexer)
	: _MOV			 { {"mov",true}, {"adr",true}, {"ldr",true} },
	  _PUSH_AND_POP  { {"push", true}, {"pop", true} },
	  _ARITHMETIC 	 { {"add", true}, {"mul", true}, {"sub", true} },
	  _CONDITIONAL   { {"eq", true}, {"ne", true}, {"lt", true}, 
	  				   {"gt", true}, {"le", true}, {"ge", true} },
	  _BRANCH 		 { {"b", true}, {"beq", true}, {"bne", true}, {"blt", true}, 
					   {"bgt", true}, {"ble", true}, {"bge", true} },
	  _DATASIZE		 { {".data", true}, {".byte", true}, {".halfword", true}, 
	  				   {".word", true}, {".doubleword", true} }
	  				   
{
	_lexer = lexer; 
}

// MakeConverter
// returns a converter that will convert the given lexeme correctly
// when new converters are created, they should be added here
shared_ptr<Converter> ConverterFactory::MakeConverter(string lexeme)
{
	shared_ptr<Converter> converter = 0;
	// Lexeme is label
	if (lexeme[lexeme.length()-1] == ':')
	{

	}
	else if (_BRANCH.count(lexeme))
	{
		converter = make_shared<BranchConverter>(_lexer, lexeme);
	}
	else if (_DATASIZE.count(lexeme))
	{
		converter = make_shared<DatasizeConverter>(_lexer, lexeme);
	}
	// Lexeme is instruction with conditional suffix
	else if (isConditional(lexeme))
	{
		string conditional = lexeme.substr(lexeme.length()-2, 2);
		string instruction = lexeme.substr(0,lexeme.length()-2);
		auto instructionConverter = makeInstructionConverter(instruction);
		if (instructionConverter)
		{
			converter = make_shared<ConditionalConverter>(conditional,instructionConverter);
		}
	}
	// Lexeme is instruction
	else
	{
		converter = makeInstructionConverter(lexeme);
	}
	return converter;
}

shared_ptr<InstructionConverter> ConverterFactory::makeInstructionConverter(string lexeme)
{
	shared_ptr<InstructionConverter> instructionConverter = 0;
	if (_MOV.count(lexeme))
	{
		instructionConverter = make_shared<MovConverter>(_lexer);
	}
	else if (_PUSH_AND_POP.count(lexeme))
	{
		instructionConverter = make_shared<PushAndPopConverter>(_lexer,lexeme);
	}
	else if (_ARITHMETIC.count(lexeme))
	{
		instructionConverter = make_shared<ArithmeticConverter>(_lexer,lexeme);
	}
	return instructionConverter;
}

bool ConverterFactory::isConditional(std::string lexeme)
{
	if (lexeme.length() <= 2) 
	{
		return false;
	}

	string conditional = lexeme.substr(lexeme.length()-2, 2);
	return _CONDITIONAL.count(conditional);
}

