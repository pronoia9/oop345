// Workshop 7 - STL Containers
// Sale.cpp
// 123 081 150

#include "Sale.h"
#include "TaxableProduct.h"
#include <string>
#include <sstream>

using namespace std;
namespace w7
{
	// Receives a reference to the output object and displays the sale information as shown in the sample output above.
	// The output includes column headings and the total sale amount including taxes paid.
	// The product number and cost occupy fields of width 10.
	Sale::Sale(char * fileName)
	{
		ifstream file(fileName);
		iProduct* prod;

		// while not end of file, and the product returned is not an empty one
		while (file.good() && (prod = readProduct(file)) != nullptr)
			productList.push_back(prod);  // add to the list of products
	}


	void Sale::display(ostream & os) const
	{
		double total = 0;

		os << "Product No      Cost Taxable\n";
		for (auto p : productList)
		{
			p->display(os);
			total += p->getCharge();
		}

		os << setw(10) << right << "Total"
		   << setw(10) << right << total << "\n";
	}


	// Receives a reference to the output stream and displays the product information in the form of a single line on the output stream.
	ostream & operator<<(std::ostream& os, const iProduct& product)
	{
		product.display(os);
		return os;
	}


	// Receives a reference to the input file stream, reads the next record from the stream, 
	// allocates memory for the corresponding iProduct object, 
	// copies the record information into that object and returns its address to the caller function.
	iProduct * readProduct(ifstream& is)
	{
		// read line
		string line;
		getline(is, line);

		// insert the line into a stringstream
		stringstream ss;

		// if line is not blank, return a respective product, else return nullptr
		if (!line.empty())
		{
			ss.str(line);

			// vector to hold the fields in the line
			vector<string> fields;

			// split the line by space (by default)
			string buf;
			while (ss >> buf)
				fields.push_back(buf);

			// check if there were three fields and make a product respectively
			iProduct* prod;
			if (fields.size() == 3)
				prod = new TaxableProduct(stol(fields[0]), stod(fields[1]), fields[2].c_str()[0]);
			else
				prod = new Product(stol(fields[0]), stod(fields[1]));

			return prod;
		}
		else return nullptr;
	}
}