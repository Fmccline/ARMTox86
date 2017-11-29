/*
	main.cpp
	Authors: Frank Cline, Jason Hsi, Brandon Abbot
	27 Nov 2017

	main file for converting GNU assembly to NASM assembly
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
	string input = "add r0,r1,r2\nadd r0,r0,r1\npush {r0,r1}\nmov r0,r2\nmov r0,#32\npop {r0,r1}";
	auto converter = make_shared<GNUToNASMConverter>(input);
	cout << converter->Convert() << endl;
}