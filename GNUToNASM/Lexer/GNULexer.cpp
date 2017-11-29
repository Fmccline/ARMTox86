/*
	GNULexer.cpp
	Authors: Frank Cline, Jason Hsi, Brandon Abbot
	27 Nov 2017

	cpp file for GNU lexer
*/

#include "GNULexer.h"
using std::string;

// IsEndOfInput
// returns true if the index has reached the end of the input string
bool GNULexer::IsEndOfInput()
{
	return (_index >= _input.length());
}

// isValid
// returns false if the given character is not part of a lexeme
bool GNULexer::isValid(char character)
{
	return (!isWhitespace(character) && character != ',');
}

// isWhitespace
// returns true if the given character is whitespaces
bool GNULexer::isWhitespace(char character)
{
	return (character == ' ' || character == '\n');
}

// skipWhitespace
// moves the index of the input string to the next character that is not whitespace
void GNULexer::skipWhitespace()
{
	while (!IsEndOfInput() && isWhitespace(_input[_index]))
	{
		++_index;
	}
}

// getNextCharacter
// returns the next character in the input string or 0 if at the end of input
char GNULexer::getNextCharacter()
{
	return (IsEndOfInput()) ? 0 : _input[_index++];
}

// getNextValidCharacter
// returns the next valid character 
char GNULexer::getNextValidCharacter()
{
	char c = getNextCharacter();
	while (c != 0 && !isValid(c))
	{
		c = getNextCharacter();
	}
	return c;
}

// GetNextLexeme
// returns the next lexeme in the input string
// Pre:
// 		Input is valid ARM code
// Post:
//		Returns next lexeme in input with constants and registers converted to x86
string GNULexer::GetNextLexeme()
{
	// skip whitespace to next character
	skipWhitespace();
	string lexeme = "";

	// While the character is valid, add it to the lexeme
	char character = getNextValidCharacter();
	while (!IsEndOfInput() && isValid(character))
	{
		if (isWhitespace(character))
		{
			break;
		}
		else
		{
			lexeme += character;
			character = getNextCharacter();
		}
	}
	// Converts the lexeme from ARM constant or register to x86 constant or register
	LexemeConverter lexemeConverter(lexeme);
	return lexemeConverter.Convert();
}