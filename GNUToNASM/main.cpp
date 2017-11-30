/*
	main.cpp
	Authors: Frank Cline, Jason Hsi, Brandon Abbot
	27 Nov 2017

	main file for converting ARM assembly to x86 assembly
*/
#include "GNUToNASM.h"
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

int main()
{
	string input;
	input += "add r0,r1,r2\n";
	input += "add r3,r3,#140\n";
	input += "mul r0,r1,r2\n";
	input += "mul r4,r4,#140\n";
	input += "sub r0,r1,r2\n";
	input += "sub r6,r6,r7\n";
	input += "push {r0,r1}\n";
	input += "push {r6,r7}\n";
	input += "mov r0,r2\n";
	input += "mov r0,#325";

	auto converter = make_shared<GNUToNASMConverter>(input);
	cout << "INPUT\n" << input << endl << endl;
	cout << "OUTPUT\n" << converter->Convert() << endl;
}