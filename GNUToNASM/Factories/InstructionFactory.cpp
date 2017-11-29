/*
	InstructionFactory.cpp
	Authors: Frank Cline, Jason Hsi, Brandon Abbot
	28 Nov 2017

	cpp file for factory that creates instruction converters
*/
#include "InstructionFactory.h"
using std::shared_ptr;
using std::make_shared;
using std::static_pointer_cast;
using std::string;
using std::move;


InstructionFactory::InstructionFactory(shared_ptr<GNULexer> & lexer)
	: _MOV { {"mov",true}, {"adr",true}, {"ldr",true} },
	  _PUSH { {"push", true} },
	  _ADD { {"add", true} }
{
	_lexer = lexer; 
}

// MakeInstructionConverter
// returns a converter that will convert the given lexeme correctly
// when converters are created, they should be added here
shared_ptr<Converter> InstructionFactory::MakeInstructionConverter(string lexeme)
{
	shared_ptr<Converter> converter = 0;
	if (_MOV.count(lexeme))
	{
		converter = make_shared<MovConverter>(_lexer);
	}
	else if (_PUSH.count(lexeme))
	{
		converter = make_shared<PushConverter>(_lexer);
	}
	else if (_ADD.count(lexeme))
	{
		converter = make_shared<AddConverter>(_lexer);
	}
	return converter;
}