#pragma once
#include <iostream>

class Something
{
private:
	std::string * table;
	int           count;

public:
	Something()                     : table(nullptr), count(0) {}         // Constructor
	Something(const Something& rhs) : table(rhs.table), count(rhs.count   // Copy Constructor
	{
		*this = rhs;
	}
	Something(Something&& rhs)      : table(rhs.table), count(rhs.count)  // Move Constructor
	{
		delete [] rhs.table;
		rhs.count = 0;
	}
	Something& operator = (const Something& rhs)                          // Copy Assignment Operator
	{
		if (this != &rhs)
		{
		}
		return *this;
	}
	Something&& opeator = (Something&& rhs)                               // Move Assignment Operator
	{
		if (this != &rhs)
		{
		}
		return move(*this);
	}
	~Something();                                                         // Destructor
}