#pragma once
#include "Pair.h"

class Fraction :
	public Pair
{
public:
	Fraction(); 
	Fraction(int, int); 
	Fraction(const Fraction&); 
	~Fraction();
	Fraction& operator=(const Fraction&);
	bool operator==(const Fraction&);
	bool operator!=(const Fraction&);
	bool operator>=(const Fraction&);
	bool operator<=(const Fraction&);
	bool operator>(const Fraction&);
	bool operator<(const Fraction&);
	int Part();
	void Compare() {};
	void Show(); 
	friend istream& operator>>(istream& in, Fraction& f);
	friend ostream& operator<<(ostream& out, const Fraction& f);
};