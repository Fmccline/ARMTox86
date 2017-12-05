/*
	main.cpp
	Authors: Frank Cline, Jason Hsi, Brandon Abbott
	27 Nov 2017

	main file for converting ARM assembly to x86 assembly
*/
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

void testPush()
{
	string testName, input, expectedOutput;

	testName = "push instruction";

	input += "push {r0}\n";
	input += "push {r0, r1, r2,    r3}\n";

	expectedOutput += "push rax\n";
	expectedOutput += "push rax\n";
	expectedOutput += "push rsi\n";
	expectedOutput += "push rdx\n";
	expectedOutput += "push r8\n";

	Test t(testName, input, expectedOutput);
	cout << t.GetTestResults() << endl;
}

void testPop()
{
	string testName, input, expectedOutput;

	testName = "pop instruction";

	input += "pop {r0}\n";
	input += "pop {r0, r1, r2,    r3}\n";

	expectedOutput += "pop rax\n";
	expectedOutput += "pop r8\n";
	expectedOutput += "pop rdx\n";
	expectedOutput += "pop rsi\n";
	expectedOutput += "pop rax\n";

	Test t(testName, input, expectedOutput);
	cout << t.GetTestResults() << endl;
}

void testCondtionals()
{
	string testName, input, expectedOutput;

	testName = "condtional suffixes";

	input += "movgt r0,r1\n";
	input += "addlt r0,r1,r1\n";
	input += "subeq r0,r1,r2\n";
	input += "mulge r0,r1,r2\n";
	input += "pushle {r0,r1,r2}\n";
	input += "popne {r0,r1}\n";

	expectedOutput += "Honestly idk\n";

	Test t(testName, input, expectedOutput);
	cout << t.GetTestResults() << endl;
}


int main()
{
	testMov();
	testArithmetic();
	testPush();
	testPop();
	testCondtionals();
}
