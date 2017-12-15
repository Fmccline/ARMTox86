/*
BranchConverter.h
Authors: Frank Cline, Jason Hsi, Brandon Abbot
04 Dec 2017

cpp file for class for ARM data conversions
MADE BY JASON
*/

#ifndef DATASIZE_CONVERTER_H_INCLUDED
#define DATASIZE_CONVERTER_H_INCLUDED

#include "Converter.h"
#include "../Lexer/GNULexer.h"

#include <memory>
#include <string>

class DatasizeConverter : public Converter
{
private:
	std::shared_ptr<GNULexer> _lexer;
	std::string _datasize, _param0;
public:
	DatasizeConverter(std::shared_ptr<GNULexer> & lexer, std::string datasize);
	std::string Convert() override;
};

#endif // DATASIZE_CONVERTER_H_INCLUDED
