/*
	MovConverter.h
	Authors: Frank Cline, Jason Hsi, Brandon Abbot
	28 Nov 2017

	header file for class that converts the mov instruction
*/

#ifndef MOV_CONVERTER_H_INCLUDED
#define MOV_CONVERTER_H_INCLUDED

#include "Converter.h"
#include "../Lexer/GNULexer.h"

#include <memory>
#include <string>

class MovConverter : public Converter
{
private:
	std::shared_ptr<GNULexer> _lexer;
	std::string _param0, _param1;
public:
	MovConverter(std::shared_ptr<GNULexer> & lexer);
	std::string Convert() override;
};

#endif // MOV_CONVERTER_H_INCLUDED