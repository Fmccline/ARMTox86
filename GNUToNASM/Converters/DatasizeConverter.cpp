/*
BranchConverter.cpp
Authors: Frank Cline, Jason Hsi, Brandon Abbot
04 Dec 2017

cpp file for class for branch instructions
MADE BY JASON
*/
#include "DatasizeConverter.h"

#include <iostream>
using std::cout;
using std::endl;

DatasizeConverter::DatasizeConverter(std::shared_ptr<GNULexer>& lexer, std::string datasize)
{
	_datasize = datasize;
	_lexer = lexer;
	_param0 = _lexer->GetNextLexeme();
}

std::string DatasizeConverter::Convert()
{
	if (_datasize == ".data")
	{
		_datasize = "SECTION .DATA";
		_param0 = "";
	}
	else if (_datasize == ".byte") 
	{
		_datasize = "db";
	}
	else if (_datasize == ".halfword") 
	{
		_datasize = "dw";
	}
	else if (_datasize == ".word")
	{
		_datasize = "dd";
	}
	else if (_datasize == ".doubleword")
	{
		_datasize = "dq";
	}
	return _datasize + " " +_param0 + "\n";
}
