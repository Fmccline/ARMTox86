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
#include "Factories/ConverterFactory.h"
#include "FileIO/fileIO.h"

#include <memory>
#include <string>

// GNUToNASMConverter
// Converts GNU assembly to NASM assemlby by turning the GNU code into lexemes and 
// converting that to NASM
class GNUToNASMConverter : public Converter
{
private:
	std::string _armCode;
	std::unique_ptr<Fileinout> _fileInOut;
	std::shared_ptr<GNULexer> _lexer;
	std::shared_ptr<ConverterFactory> _converterFactory;
	std::string convertLexeme(std::string lexeme);
public:
	GNUToNASMConverter() { _fileInOut = std::make_unique<Fileinout>(); }
	GNUToNASMConverter(std::string armCode):_armCode(armCode) { _fileInOut = std::make_unique<Fileinout>(); }
	std::string ConvertFromString(const std::string & armCode);
	std::string ConvertFromFile(const std::string & filename);
	void WriteToFile(const std::string & filename);
	std::string Convert() override;
};

#endif // GNU_TO_NASM_H_INCLUDED