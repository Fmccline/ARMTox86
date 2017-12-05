/*
	main.cpp
	Authors: Frank Cline, Jason Hsi, Brandon Abbott
	27 Nov 2017

	main file for converting ARM assembly to x86 assembly
*/
#include "GNUToNASM.h"
#include "Test.h"
#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <memory>
using std::shared_ptr;
using std::make_shared; 
#include <exception>
using std::exception;
#include <cassert>

void testMov()
{
	string testName, input, expectedOutput;

	testName = "mov instruction";

	input += "mov r0,r1\n";
	input += "mov r0,#80\n";
	input += "adr r1,labelGuy\n";
	input += "ldr r0,[r1]";

	expectedOutput += "mov rax,rsi\n";
	expectedOutput += "mov rax,80\n";
	expectedOutput += "mov rsi,labelGuy\n";
	expectedOutput += "mov rax,[rsi]\n";

	Test t(testName, input, expectedOutput);
	cout << t.GetTestResults() << endl;
}

void testArithmetic()
{
	string testName, input, expectedOutput;

	testName = "Arithmetic instructions";

	input += "add r0,r1,r2\n";
	input += "add r0,r0,#80\n";
	input += "add r0,#80,#100\n";

	input += "sub r0,r1,r2\n";
	input += "sub r0,r0,#80\n";
	input += "sub r0,#80,#100\n";

	input += "mul r0,r1,r2\n";
	input += "mul r0,r0,#80\n";
	input += "mul r0,#80,#100\n";

	expectedOutput += "mov rax,rsi\n";
	expectedOutput += "add rax,rdx\n";
	expectedOutput += "add rax,80\n";
	expectedOutput += "mov rax,80\n";
	expectedOutput += "add rax,100\n";

	expectedOutput += "mov rax,rsi\n";
	expectedOutput += "sub rax,rdx\n";
	expectedOutput += "sub rax,80\n";
	expectedOutput += "mov rax,80\n";
	expectedOutput += "sub rax,100\n";

	expectedOutput += "mov rax,rsi\n";
	expectedOutput += "imul rax,rdx\n";
	expectedOutput += "imul rax,80\n";
	expectedOutput += "mov rax,80\n";
	expectedOutput += "imul rax,100\n";

	Test t(testName, input, expectedOutput);
	cout << t.GetTestResults() << endl; 
}

int main()
{
	testMov();
	testArithmetic();
}
