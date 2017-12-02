/*
	ConditionalConverter.h
	Authors: Frank Cline, Jason Hsi, Brandon Abbot
	1 Dec 2017

	source file for class that converts conditional suffixes for ARM instructions
*/
#include "ConditionalConverter.h"
using std::shared_ptr;
using std::string;
using std::to_string;
using std::pair;

int ConditionalConverter::_conditionalCount = 0;

ConditionalConverter::ConditionalConverter(string conditional, shared_ptr<InstructionConverter> & instructionConverter)
:_CONDITIONALS { {"eq", "e"}, {"ne", "ne"}, {"lt", "l"}, {"gt", "g"}}
{
	_conditional = (_CONDITIONALS.count(conditional)) ? _CONDITIONALS.at(conditional) : conditional;
	_instructionConvertion = instructionConverter->Convert();

	auto parameters = instructionConverter->GetConditionalParameters();
	_compareParam0 = parameters.first;
	_compareParam1 = parameters.second;

	_conditionalCount++;
}

// Convert
// converts the ARM mov instruction to x86
string ConditionalConverter::Convert()
{
	string convertion; // value to be returned
	string conditionalCount = to_string(_conditionalCount);
	string isTrueLabel = "isTrue" + conditionalCount;
	string isFalseLabel = "isFalse" + conditionalCount;

	string compare = "cmp " + _compareParam0 + "," + _compareParam1 + "\n";
	string conditional = "j" + _conditional + " " + isTrueLabel + "\n";
	string isTrue = isTrueLabel + ":\n";
	string isFalse = isFalseLabel + ":\n";
	string jmpFalse = "jmp " + isFalseLabel + "\n";

	convertion = compare + conditional + jmpFalse + isTrue + _instructionConvertion + isFalse;
	return convertion;
}