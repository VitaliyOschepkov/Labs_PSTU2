#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Temperature.h"
#include "List.h"

using namespace std;

int fileMake(const char* f_name, List& l)
{
	fstream stream(f_name, ios::out | ios::trunc);    
	if (!stream)
		return -1;    
	int n = 30;
	l.clear();
	for (int i = 0; i < n; i++)
	{
		int t = rand() % 60 - 30;
		Temperature w(i + 1, t);
		l.push_back(w);
		stream << w << "\n";     
	}
	stream.close();    
	return n;     
}
int fileSave(const char* f_name, List& l)
{
	fstream stream("temp", ios::out);	
	if (!stream)
		return -1;
	int n = 0;
	Temperature temp;
	for (Lit i = l.begin(); i != l.end(); i++, n++)
	{
		temp = (*i);
		stream << temp;
	}
	stream.close();
	remove(f_name);
	rename("temp", f_name);
	return n;
}
int fileOpen(const char* f_name, List& l)
{
	fstream stream(f_name, ios::in);
	Temperature temp;
	int n = 0;
	if (!stream)
		return -1;
	if (l.size() > 0)
		l.clear();
	while (stream >> temp)
	{
		l.push_back(temp);
		n++;
	}
	return n;
}