#pragma once
#include <string>

using namespace std;

class Student
{
	string fullname;
	string group;
	float averagemark;
public:
	Student(); 
	Student(string, string, float); 
	Student(const Student&); 
	~Student(); 
	string getFullname();
	string getGroup();
	float getAveragemark();
	void setFullname(string);
	void setGroup(string);
	void setAveragemark(float);
	void Show();
};