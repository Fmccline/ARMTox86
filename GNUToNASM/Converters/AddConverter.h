/*
	AddConverter.h
	Frank Cline
	28 Nov 2017

	cpp file for class that converts the add instruction
*/

#ifndef ADD_CONVERTER_H_INCLUDED
#define ADD_CONVERTER_H_INCLUDED

#include "Converter.h"
#include "../Lexer/GNULexer.h"

#include <memory>
#include <string>


class AddConverter : public Converter
{
private:
	std::shared_ptr<GNULexer> _lexer;
	std::string _param0, _param1, _param2;
public:
	AddConverter(std::shared_ptr<GNULexer> & lexer);
	std::string Convert() override;
};

#endif // ADD_CONVERTER_H_INCLUDED