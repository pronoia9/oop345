// Jay Ansin
// cansin@myseneca.ca
// 123 08 1150
// Workshop 2 - unsigned int, Enumerations, String Class and File I/O 
// Stations.h

#pragma once

#include <iostream>

namespace w2
{
	class Stations
	{
	private:
		int stationCount;
		Station* stationTable;
		
	public:
		Stations(char* f)
		void update() const  // Accepts the number of passes sold and updates the data for each station in turn
		void restock() const // Accepts the number of passes added and updates the data for each station in turn
		void report() const  // Reports the number of passes currently available at each station
	};
}