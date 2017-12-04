/*
	Test.cpp
	Authors: Frank Cline, Jason Hsi, Brandon Abbot
	4 Dec 2017

	source file for ARM to x86 convertion tester
*/

#include "Test.h"
using std::string;
using std::make_shared;

Test::Test(const string & testName, const string & input, const string & expectedOutput): 
	_testName(testName), _input(input), _expectedOutput(expectedOutput)
{
	auto converter = make_shared<GNUToNASMConverter>(input);
	_output = converter->Convert();
}

string Test::GetTestResults()
{
	string result;
	result += "Testing " +  _testName + "...\n";
	result += _testName + ": ";

	if (_output != _expectedOutput)
	{
		result += "FAILED\n";
		result += "OUTPUT\n" + _output + "\n";
		result += "EXPECTED OUTPUT\n" + _expectedOutput + "\n";
	}
	else
	{
		result += "PASSED";
	}
	return result;
}
