/*
	BranchConverter.h
	Authors: Frank Cline, Jason Hsi, Brandon Abbot
	04 Dec 2017

	cpp file for class that converts branch instructions
	MADE BY JASON
*/

#ifndef BRANCH_CONVERTER_H_INCLUDED
#define BRANCH_CONVERTER_H_INCLUDED

#include "Converter.h"
#include "../Lexer/GNULexer.h"

#include <memory>
#include <string>

// Currently only converts signed values
class BranchConverter : public Converter
{
private:
	std::shared_ptr<GNULexer> _lexer;
	std::string _instruction, _param0;
public:
	BranchConverter(std::shared_ptr<GNULexer> & lexer, std::string instruction);
	std::string Convert() override;
};

#endif // BRANCH_CONVERTER_H_INCLUDED