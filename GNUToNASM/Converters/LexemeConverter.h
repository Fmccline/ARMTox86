/*
	LexemeConverter.h
	Authors: Frank Cline, Jason Hsi, Brandon Abbot
	29 Nov 2017

	header file for class that converts ARM registsers and constants to x86
*/

#ifndef LEXEME_CONVERTER_H_INCLUDED
#define LEXEME_CONVERTER_H_INCLUDED

#include "Converter.h"

#include <memory>
#include <string>


class LexemeConverter : public Converter
{
private:
	std::string _lexeme;
	std::string convertConstant();
	std::string convertRegister();
public:
	LexemeConverter(std::string lexeme);
	std::string Convert() override;
};

#endif // LEXEME_CONVERTER_H_INCLUDED