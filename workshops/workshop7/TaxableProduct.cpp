// Workshop 7 - STL Containers
// TaxableProduct.cpp
// 123 081 150

#include "TaxableProduct.h"
#include <iomanip>

using namespace std;
namespace w7
{
	TaxableProduct::TaxableProduct(const int no, const double cost, const char tax) : Product(no, cost), _tax(tax)
	{ }


	// Returns the price chargable to the customer.
	double TaxableProduct::getCharge() const
	{
		// HST and PST tax codes (13% and 8%)
		if (_tax == 'H') return Product::getCharge() * 1.13;
		return Product::getCharge() * 1.08;
	}


	// Receives a reference to the output stream and inserts the product information in the form of a single line into the output stream.
	void TaxableProduct::display(ostream & os) const
	{
		//Product::display(os);
		//if (_tax == 'H') os << " HST";
		//else             os << " PST";
		os  << setw(10) << _prodNo
			<< setw(10) << fixed << setprecision(2) << _cost
			<< ' ' << (_tax == 'H' ? "HST" : "PST") << endl;
	}
}