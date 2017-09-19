// Workshop 7 - STL Containers
// iProduct.h

#pragma once
#include <iostream>
#include <fstream>

namespace w7 
{
	// ABSTRACT CLASS
	// The iProduct hierarchy holds information about the different products purchased by a customer. 
	class iProduct 
	{
	public:
		virtual double getCharge() const = 0; 
		virtual void display(std::ostream&) const = 0;
	};

	std::ostream& operator<<(std::ostream&, const iProduct&);
	iProduct* readProduct(std::ifstream&);
}