// Workshop 7 - STL Containers
// Product.cpp
// 123 081 150

#include <iomanip>
#include "Product.h"

using namespace std;
namespace w7
{
	Product::Product(const int no, const double cost) : _prodNo(no), _cost(cost)
	{  }

	
	// Returns the price chargable to the customer.
	double Product::getCharge() const
	{
		return _cost;
	}


	// Receives a reference to the output stream and inserts the product information in the form of a single line into the output stream.
	void Product::display(ostream & os) const
	{
		os  << setw(10) << right << _prodNo
			<< setw(10) << right << fixed << setprecision(2) << _cost << ' ' << endl;
	}
}