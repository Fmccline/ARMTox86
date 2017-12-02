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
	input += "addgt r0,r1,r2\n";
	input += "moveq r0,r1\n";

	auto converter = make_shared<GNUToNASMConverter>(input);
	cout << "INPUT\n" << input << endl << endl;
	cout << "OUTPUT\n" << converter->Convert() << endl;
}