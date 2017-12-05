/*
	PushAndPopConverter.h
	Authors: Frank Cline, Jason Hsi, Brandon Abbot
	30 Nov 2017

	header file for class that converts the GNU push and pop instructions
*/

#ifndef PUSH_AND_POP_CONVERTER_H_INCLUDED
#define PUSH_AND_POP_CONVERTER_H_INCLUDED

#include "Converter.h"
#include "../Lexer/GNULexer.h"

#include <memory>
#include <string>
#include <vector>
#include <algorithm>

// PushConverter
// Converts the GNU push instruction to NASM
class PushAndPopConverter : public Converter
{
private:
	std::shared_ptr<GNULexer> _lexer;
	std::string _instruction;
	std::vector<std::string> _parameters;
	void setParameters();
public:
	PushAndPopConverter(std::shared_ptr<GNULexer> & lexer, std::string instruction);
	std::string Convert() override;
};

#endif // PUSH_AND_POP_CONVERTER_H_INCLUDED