// Workshop 7 - STL Containers
// TaxableProduct.h
// 123 081 150

#pragma once
#include "Product.h"

namespace w7
{
	// Derives from Product and holds additional information about the product's taxable status
	class TaxableProduct : public Product
	{
	private:
		double taxes[2] = { 1.13, 1.08 };
		char _tax;

	public:
		TaxableProduct(const int no, const double cost, const char tax);
		double getCharge() const;
		void display(std::ostream& os) const;
	};
}