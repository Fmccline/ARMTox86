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
	string input = "add r0,r1,r2\nadd r3,r4,#140\npush {r0,r1}\npush {r6,r7}\nmov r0,r2\nmov r0,#325";
	auto converter = make_shared<GNUToNASMConverter>(input);
	cout << "INPUT\n" << input << endl << endl;
	cout << "OUTPUT\n" << converter->Convert() << endl;
}