/*
	PushConverter.h
	Authors: Frank Cline, Jason Hsi, Brandon Abbot
	28 Nov 2017

	cpp file for class that converts the GNU push instruction
*/

#ifndef PUSH_CONVERTER_H_INCLUDED
#define PUSH_CONVERTER_H_INCLUDED

#include "Converter.h"
#include "../Lexer/GNULexer.h"

#include <memory>
#include <string>
#include <vector>

// PushConverter
// Converts the GNU push instruction to NASM
class PushConverter : public Converter
{
private:
	std::shared_ptr<GNULexer> _lexer;
	std::vector<std::string> _parameters;
	void setParameters();
public:
	PushConverter(std::shared_ptr<GNULexer> & lexer);
	std::string Convert() override;
};

#endif // PUSH_CONVERTER_H_INCLUDED