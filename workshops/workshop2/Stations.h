#pragma once
#include "Station.h"

namespace w2
{
	class Stations
	{
	private:
		int stationCount;
		Station* stationsTable;
		char* filename;

	public:
		Stations();
		Stations(char* f);
		~Stations();
		void update() const;  
		void restock() const; 
		void report() const; 
	};
}