/*
	BitwiseConverter.h
	Authors: Frank Cline, Jason Hsi, Brandon Abbot
	04 Dec 2017

	header file for class that converts bitwise shift instructions
	MADE BY JASON
*/

#ifndef BITWISE_CONVERTER_H_INCLUDED
#define BITWISE_CONVERTER_H_INCLUDED

#include "Converter.h"
#include "../Lexer/GNULexer.h"

#include <memory>
#include <string>

// Currently only converts signed values
class BitwiseConverter : public Converter
{
private:
	std::shared_ptr<GNULexer> _lexer;
	std::string _instruction, _param0;
public:
	BitwiseConverter(std::shared_ptr<GNULexer> & lexer, std::string instruction);
	std::string Convert() override;
};

#endif // BITWISE_CONVERTER_H_INCLUDED