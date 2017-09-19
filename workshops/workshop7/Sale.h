// Workshop 7 - STL Containers
// Sale.h
// 123 081 150

#pragma once
#include <vector>
#include <iomanip>
#include "iProduct.h"

namespace w7
{
	// Sale holds information about the set of products sold to a customer.
	class Sale
	{
	private:
		std::vector<iProduct*> productList;

	public:
		// Upon instantiation, a Sale object receives the address of a C-style null-terminated string that holds the name of a file.
		// This file contains the list of products sold to the customer.
		// The one-argument constructor copies the product information into an STL container. 
		// Since the products are polymorphic objects, your class stores and accesses them through a set of pointers to the objects.
		Sale(char* fileName); 
		void display(std::ostream& os) const;
	};
}