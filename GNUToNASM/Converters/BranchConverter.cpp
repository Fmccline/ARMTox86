/*
	BranchConverter.cpp
	Authors: Frank Cline, Jason Hsi, Brandon Abbot
	04 Dec 2017

	cpp file for class for branch instructions
	MADE BY JASON
*/

#include "BranchConverter.h"
using std::shared_ptr;
using std::string;

// TODO: remove include
#include <iostream>
using std::endl;
using std::cout;

BranchConverter::BranchConverter(shared_ptr<GNULexer> & lexer, string instruction)
{
	_instruction = instruction;
	_lexer = lexer;
	_param0 = _lexer->GetNextLexeme();
}

// Convert
// converts the ARM add instruction to x86
string BranchConverter::Convert()
{
	cout << "0: " << _param0 << endl;
	if (_instruction == "b") {
		_instruction = "jmp";
	}
	else if (_instruction == "beq") {
		_instruction = "je";
	}
	else if (_instruction == "bne") {
		_instruction = "jne";
	}
	else if (_instruction == "blt") {
		_instruction = "jl";
	}
	else if (_instruction == "bgt") {
		_instruction = "jg";
	}
	else if (_instruction == "ble") {
		_instruction = "jle";
	}
	else if (_instruction == "bge") {
		_instruction = "jge";
	}
	return _instruction + " " + _param0 + "\n";
}