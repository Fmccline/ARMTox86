/*
	GNUToNASM.h
	Authors: Frank Cline, Jason Hsi, Brandon Abbot
	27 Nov 2017

	Header file for ARM to x86 converter
*/

#ifndef GNU_TO_NASM_H_INCLUDED
#define GNU_TO_NASM_H_INCLUDED

#include "Converters/Converter.h"
#include "Lexer/GNULexer.h"
#include "Factories/InstructionFactory.h"

#include <memory>
#include <string>

// GNUToNASMConverter
// Converts GNU assembly to NASM assemlby by turning the GNU code into lexemes and 
// converting that to NASM
class GNUToNASMConverter : public Converter
{
private:
	std::shared_ptr<GNULexer> _lexer;
	std::shared_ptr<InstructionFactory> _instructionFactory;
	std::string convertLexeme(std::string lexeme);
public:
	GNUToNASMConverter(std::string gnuCode);
	std::string Convert() override;
};

#endif // GNU_TO_NASM_H_INCLUDED