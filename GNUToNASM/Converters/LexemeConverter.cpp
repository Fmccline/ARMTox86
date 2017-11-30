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
	if (firstChar == '#')
	{
		return convertConstant();
	}
	else if (firstChar == 'r' || firstChar == '{')
	{
		return convertRegister();
	}
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
string LexemeConverter::convertRegister()
{
	string armRegister, x86Register;
	int startRegister = 0;
	int registerLength = _lexeme.length();

	if (_lexeme[0] == '{')
	{
		registerLength = _lexeme.length() - 1;
		startRegister = 1;
	}
	else if (_lexeme[_lexeme.length()-1] == '}')
	{
		registerLength = _lexeme.length() - 1;
	}
	
	armRegister = _lexeme.substr(startRegister,registerLength);
	x86Register = (_registers.count(armRegister)) ? _registers.at(armRegister) : armRegister;
	return _lexeme.replace(startRegister, registerLength, x86Register); 
}