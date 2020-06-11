#pragma once
#include "Person.h"

class Student :
	public Person
{
private:
	float rating; 
public:
	Student(); 
	Student(string, int, float); 
	Student(const Student&);
	~Student();
	float getRating();
	void setRating(float);
	Student& operator=(const Student&);
	void Show();
	void Input();
};