/*
	ArithmeticConverter.h
	Authors: Frank Cline, Jason Hsi, Brandon Abbot
	28 Nov 2017

	cpp file for class that converts arithmetic instructions
*/

#ifndef ARITHMETIC_CONVERTER_H_INCLUDED
#define ARITHMETIC_CONVERTER_H_INCLUDED

#include "Converter.h"
#include "../Lexer/GNULexer.h"

#include <memory>
#include <string>
#include <utility>

class ArithmeticConverter : public Converter
{
private:
	std::shared_ptr<GNULexer> _lexer;
	std::string _instruction, _param0, _param1, _param2;
public:
	ArithmeticConverter(std::shared_ptr<GNULexer> & lexer, std::string instruction);
	std::string Convert() override;
};

#endif // ARITHMETIC_CONVERTER_H_INCLUDED