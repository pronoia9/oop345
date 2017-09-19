// Workshop 8 - STL Algorithms
// DataTable.h
// 123 081 150

#pragma once
#include <fstream>    // file streams
#include <vector>
#include <utility>
#include <sstream>
#include <iostream>   // I/O streams, cout, cin, �
#include <iomanip>
#include <numeric>    // accumulate, inner_product, �
#include <algorithm>  // sort, copy, �

namespace w8
{
	// A class template for performing statistical analysis on data stored in text files
	template<class T>
	class DataTable
	{
		std::vector<T> x, y;
		int width, decimals;

	public:
		DataTable(std::ifstream& file, int width, int decimals) : width(width), decimals(decimals)
		{
			std::string line;
			while (getline(file, line))
			{
				std::stringstream ss;

				if (!line.empty())
				{
					ss.str(line);

					T tx, ty;
					ss >> tx >> ty;

					x.push_back(tx);
					y.push_back(ty);
				}
			}
		}

		// returns the mean value of the dependent coordinate
		T mean() const
		{
			T yTotal = std::accumulate(y.begin(), y.end(), 0.0);

			return (yTotal / y.size());
		}

		// returns the standard deviation of the dependent coordinates
		T sigma() const
		{
			T meanVal = mean(), totDeviation = 0;

			for (auto e : y) 
			{
				totDeviation += pow(e - meanVal, 2);
			}

			if (y.size() - 1) 
			{
				totDeviation = sqrt(totDeviation / (y.size() - 1));
			}

			return totDeviation;
		}

		// returns the median value of the dependent coordinate
		T median() const
		{
			std::vector<T> copy = y;

			std::sort(copy.begin(), copy.end());
			T median = copy[copy.size() / 2];

			return median;
		}

		// returns the slope and intercept for the data set
		void regression(T& slope, T& y_intercept) const
		{
			T averageX = std::accumulate(x.begin(), x.end(), 0.0) / x.size();
			T averageY = std::accumulate(y.begin(), y.end(), 0.0) / y.size();

			T numerator = 0.0, denominator = 0.0;

			for (int i = 0; i < x.size(); ++i)
			{
				numerator   += (x[i] - averageX) * (y[i] - averageY);
				denominator += (x[i] - averageX) * (x[i] - averageX);
			}

			slope = numerator / denominator;
			y_intercept = averageY - (slope * averageX);
		}

		// displays the data pairs as shown below
		void display(std::ostream& os) const
		{
			os << std::setw(width) << "x" << std::setw(width) << "y" << std::endl;

			for (int i = 0; i < x.size(); i++)
			{
				os << std::setw(width) << std::fixed << std::setprecision(decimals) << x[i]
				   << std::setw(width) << std::fixed << std::setprecision(decimals) << y[i] << std::endl;
			}
		}
	};

	// inserts the data generated by display() into the output stream
	template<class T>
	std::ostream& operator<<(std::ostream& os, const DataTable<T>& dt)
	{
		dt.display(os);
		return os;
	}
}