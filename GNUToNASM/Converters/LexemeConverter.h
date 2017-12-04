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
#include <unordered_map>
#include <string>

// LexemeConverter
// Converts a given lexeme from an ARM constant or register to an x86 constant or register
class LexemeConverter : public Converter
{
private:
	// string that holds the lexeme to be converted
	std::string _lexeme;
	// table where the (key,value) pairs are (ARM registers, x86 registers)
	const std::unordered_map<std::string,std::string> _registers;
	std::string convertConstant();
	std::string convertRegister(const std::string & armRegister);
public:
	LexemeConverter(std::string lexeme);
	std::string Convert() override;
};

#endif // LEXEME_CONVERTER_H_INCLUDED