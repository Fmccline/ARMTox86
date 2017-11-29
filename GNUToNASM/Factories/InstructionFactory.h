/*
	InstructionFactory.h
	Frank Cline
	28 Nov 2017

	header file for factory that creates converters
*/

#ifndef INSTRUCTION_FACTORY_H_INCLUDED
#define INSTRUCTION_FACTORY_H_INCLUDED

#include "../Converters/Converter.h"
#include "../Converters/MovConverter.h"
#include "../Converters/PushConverter.h"
#include "../Converters/AddConverter.h"
#include "../Lexer/GNULexer.h"

#include <memory>
#include <string>
#include <unordered_map>

// InstructionFactory
// Creates an instruction converter given a lexeme
class InstructionFactory
{
private:
	// Constant hash tables for storing ARM instructions
	const std::unordered_map<std::string,bool> _MOV;
	const std::unordered_map<std::string,bool> _PUSH;
	const std::unordered_map<std::string,bool> _ADD;
	std::shared_ptr<GNULexer> _lexer;
public:
	InstructionFactory(std::shared_ptr<GNULexer> & lexer);
	std::shared_ptr<Converter> MakeInstructionConverter(std::string lexeme);
};

#endif // INSTRUCTION_FACTORY_H_INCLUDED