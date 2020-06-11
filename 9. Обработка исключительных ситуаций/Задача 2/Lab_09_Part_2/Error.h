#pragma once
#include <iostream>
#include <string>

using namespace std;

class Error
{
	string str;
public:
	Error(string s) { str = s; }
	void What() { cout << str << "\n"; }
};