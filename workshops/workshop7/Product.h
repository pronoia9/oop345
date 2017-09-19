// Workshop 7 - STL Containers
// Product.h
// 123 081 150

#pragma once
#include "iProduct.h"

namespace w7 
{
	// Holds information about a product that consists of its product number and its cost.
	class Product : public iProduct
	{
	protected:
		int _prodNo;
		double _cost;

	public:
		Product(const int no, const double cost);
		double getCharge() const;
		void display(std::ostream& os) const;
	};

	//std::ostream& operator<<(std::ostream& os, const iProduct& product);
	//iProduct* readProduct(std::ifstream& file);
}