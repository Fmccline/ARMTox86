/*
	GNULexer.h
	Frank Cline
	27 Nov 2017

	Header file for GNU lexer
*/

#ifndef GNU_LEXER_H_INCLUDED
#define GNU_LEXER_H_INCLUDED

#include <string>

// GNULexer
// Takes in a string of GNU code and splits the code into lexemes
class GNULexer
{
private:
	std::string _input;
	int _index;
	bool isValid(char character);
	bool isWhitespace(char c);
	void skipWhitespace();
	char getNextCharacter();
	char getNextValidCharacter();

public:
	GNULexer(std::string input): _input(input), _index(0) {}
	std::string GetNextLexeme();
	bool IsEndOfInput();
};

#endif // GNU_LEXER_H_INCLUDED