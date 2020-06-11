#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Time.h"

using namespace std;

int fileMake(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc); 
	if (!stream)
		return -1; 
	Time t;
	int n;
	cout << "количество записей: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		stream << t << "\n";
	}
	stream.close(); 
	return n; 
}
int filePrint(const char* f_name)
{
	fstream stream(f_name, ios::in); 
	if (!stream)
		return -1; 
	Time t;
	int i = 0;
	while (stream >> t)
	{
		cout << t << "\n";
		i++;
	}
	stream.close();
	return i; 
}
int fileDel(const char* f_name, int k)
{
	fstream temp("temp", ios::out); 
	fstream stream(f_name, ios::in); 
	if (!stream)
		return -1; 
	Time t;
	int i = 0;
	while (stream >> t)
	{
		i++;
		if (i != k)
			temp << t; 
	}
	stream.close();
	temp.close();
	remove(f_name); 
	rename("temp", f_name); 
	return i; 
}
int fileAdd(const char* f_name, int k, Time tt)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream)
		return -1;
	Time t;
	int i = 0;
	int l = 0;
	while (stream >> t)
	{
		i++;
		if (i == k)
		{
			temp << tt;
			l++;
		}
		temp << t;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;
}
int addToEnd(const char* f_name, Time t)
{
	fstream stream(f_name, ios::app);
	if (!stream)
		return -1;
	stream << t;
	return 1;
}
int fileCheange(const char* f_name, int k, Time tt)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream)
		return -1;
	Time t;
	int i = 0;
	int l = 0;
	char x;
	while (stream >> t)
	{
		i++;
		if (i == k)
		{
			temp << tt;
			l++;
		}
		else
			temp << t;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;
}
int delCompare(const char* f_name)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in); 
	if (!stream)
		return -1; 
	Time t1, t2;
	int i = 0;
	cout << "¬ведите значение удал€емых элементов:\n";
	cin >> t2;
	while (stream >> t1)
	{
		i++;
		if (!(t1 == t2))
			temp << t1;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name); 
	return i; 
}
int addTime(const char* f_name, const Time& t)
{
	fstream temp("temp", ios::out); 
	fstream stream(f_name, ios::in); 
	if (!stream)
		return -1; 
	Time t1, t2;
	int i = 0;
	cout << "¬ведите значение элемента дл€ добавлени€ константы:\n";
	cin >> t2;
	while (stream >> t1)
	{
		i++;
		if (t1 == t2)
		{
			t1 = t1 + t;
			temp << t1;
		}
		else
			temp << t1;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name); 
	return i; 
}
int addAfter(const char* f_name, int k)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream)
		return -1;
	int i = 0;
	int l = 0;
	Time t1, t2;
	int n;
	while (stream >> t1)
	{
		i++;
		if (i == k)
		{
			cout << "¬ведите количество записей: ";
			cin >> n;
			temp << t1;
			for (int iter = 0; iter < n; iter++)
			{
				cin >> t2; 
				temp << t2; 
				l++;
			}
		}
		else temp << t1;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;
}