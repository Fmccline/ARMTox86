/*
	Test.h
	Authors: Frank Cline, Jason Hsi, Brandon Abbot
	4 Dec 2017

	Header file for ARM to x86 convertion tester
*/

#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include "GNUToNASM.h"
#include <string>
#include <memory>

// Test
// Class used to test the GNUToNASMConverter
class Test
{
private:
	std::string _testName, _input, _expectedOutput, _output;
public:
	Test(const std::string & testName, const std::string & input, const std::string & expectedOutput);
	std::string GetTestResults();
};

#endif // TEST_H_INCLUDED