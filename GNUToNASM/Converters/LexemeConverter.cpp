/*
	LexemeConverter.cpp
	Authors: Frank Cline, Jason Hsi, Brandon Abbot
	29 Nov 2017

	cpp file for class that converts ARM registsers and constants to x86
*/
#include "LexemeConverter.h"
using std::string;

// TODO: Delete include
#include <iostream>
using std::cout;
using std::endl;

LexemeConverter::LexemeConverter(string lexeme) : _lexeme(lexeme), 
	_registers
	{
		{"r0","rax"},
		{"r1","rsi"},
		{"r2","rdx"},
		{"r3","r8"},
		{"r4","rbx"},
		{"r5","r12"},
		{"r6","r13"},
		{"r7","r14"},
		{"r8","r15"},
		{"r9","rbp"},
		{"r10","rcx"},
		{"r11","r11"},
		{"r12","r9"},
		{"r13","rsp"},
		{"r14","r10"},
		{"r15","rdi"},
	}
{}

// Convert
// converts an ARM register or constant to an x86 register or constant
string LexemeConverter::Convert()
{
	char firstChar = _lexeme[0];
	char lastChar = _lexeme[_lexeme.length()-1];
	// check if lexeme is a constant
	if (firstChar == '#')
	{
		return convertConstant();
	}
	// check if lexeme is a register
	else if (firstChar == 'r')
	{
		// check if register is the last register in a push/pop instruction
		if (lastChar == '}')
		{
			string armRegister = _lexeme.substr(0,_lexeme.length()-1);
			return convertRegister(armRegister) + '}';
		}
		else
		{
			return convertRegister(_lexeme);
		}
	}
	// check if lexeme is the first register in a push/pop instruction
	else if (firstChar == '{')
	{
		bool isSingleRegister = (lastChar == '}');
		int substrLength = isSingleRegister ? _lexeme.length()-2 : _lexeme.length()-1;
		string armRegister = _lexeme.substr(1,substrLength);
		string returnValue = "{" + convertRegister(armRegister);
		return (isSingleRegister) ? returnValue + "}" : returnValue;
	}
	// check if lexeme is a register used in a ldr instruction
	else if (firstChar == '[')
	{
		string armRegister = _lexeme.substr(1,_lexeme.length()-2);
		return "[" + convertRegister(armRegister) + "]";
	}
	// else the lexeme is not a register
	else
	{
		return _lexeme;
	}
}

// convertConstant
// converts an ARM constant to an x86 constant
string LexemeConverter::convertConstant()
{
	return _lexeme.substr(1,_lexeme.length()-1);
}

// convertRegister
// converts an ARM register to an x86 register
string LexemeConverter::convertRegister(const string & armRegister)
{
	return (_registers.count(armRegister)) ? _registers.at(armRegister) : armRegister;
}