// Workshop 2 - unsigned int, Enumerations, String Class and File I/O 
// w2.cpp

#include <iostream>
#include "Stations.h"

using namespace std;
using namespace w2;

int main(int argc, char* argv[]) 
{
	cout << "\nCommand Line : ";

	for (int i = 0; i < argc; i++) 
	{
		cout << argv[i] << ' ';
	}

	cout << std::endl;

	if (argc != 2) 
	{
		cerr << "\nIncorrect number of arguments\n";
		return 1;
	}

	Stations stations(argv[1]);
	stations.update();
	stations.restock();
	stations.report();

	return 0;
}