/*
	ConverterFactory.h
	Authors: Frank Cline, Jason Hsi, Brandon Abbot
	28 Nov 2017

	header file for factory that creates converters
*/

#ifndef CONVERTER_FACTORY_H_INCLUDED
#define CONVERTER_FACTORY_H_INCLUDED

#include "../Converters/Converter.h"
#include "../Converters/MovConverter.h"
#include "../Converters/PushAndPopConverter.h"
#include "../Converters/ArithmeticConverter.h"
#include "../Lexer/GNULexer.h"

#include <memory>
#include <string>
#include <unordered_map>

// ConverterFactory
// Creates an instruction converter given a lexeme
class ConverterFactory
{
private:
	// Constant hash tables for storing ARM instructions
	const std::unordered_map<std::string,bool> _MOV;
	const std::unordered_map<std::string,bool> _PUSH_AND_POP;
	const std::unordered_map<std::string,bool> _ARITHMETIC;
	std::shared_ptr<GNULexer> _lexer;
public:
	ConverterFactory(std::shared_ptr<GNULexer> & lexer);
	std::shared_ptr<Converter> MakeConverter(std::string lexeme);
};

#endif // CONVERTER_FACTORY_H_INCLUDED