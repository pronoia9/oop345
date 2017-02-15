// Workshop 3 - Copy and Move Semantics
// Text.cpp

#include <fstream>
#include <string>
#include "Text.h"

using namespace std;
namespace w3
{
	// Creates a 'zombie'
	Text::Text() : count(0), lineTable(nullptr)
	{
		//count = 0;
		//lineTable = nullptr;
	}


	Text::Text(char * f) : count(0), lineTable(nullptr)
	{
		fstream in(f, ios::in);

		if (in.is_open())
		{
			string line;

			// count the lines
			while (getline(in, line))
			{
				count++;
			}

			//cout << "File '" << f << "' contains " << count << " lines" << endl;

			lineTable = new std::string[count];

			/*{
				cout << in.good() << "<-- good: true if none of the flags is set" << endl;
				cout << in.fail() << "<-- fail: true if ios::failbit or ios::badbit is true" << endl;
				cout << in.eof() << "<-- eof : true if ios::eof is true" << endl;
				cout << in.bad() << "<-- bad : true if ios::badbit is true" << endl;
			}
			in.clear(); // reset the EOF state
			{
				cout << "after clearing the EOF state" << endl;
				cout << in.good() << "<-- good: true if none of the flags is set" << endl;
				cout << in.fail() << "<-- fail: true if ios::failbit or ios::badbit is true" << endl;
				cout << in.eof() << "<-- eof : true if ios::eof is true" << endl;
				cout << in.bad() << "<-- bad : true if ios::badbit is true" << endl;
			}*/

			// position the file at the beginning
			in.seekp(0); // offset 0 from the beginning is the beginning

			for (size_t i = 0; i < count; i++)
			{
				getline(in, lineTable[i]);
				auto cr = lineTable[i].find('\r');
				if (cr != std::string::npos)
				{
					lineTable[i].erase(cr);
				}
			}

			in.close();

			//dump();
		}
		else
		{
			cerr << "Cannot open file '" << f << "'" << endl;
			exit(3);
		}
	}


	// Copy constructor
	Text::Text(const Text & rhs) : count(0), lineTable(nullptr)
	{
		*this = rhs;
	}


	// Copy assignment operator
	Text & Text::operator=(const Text & rhs)
	{
		if (nullptr != lineTable)
		{
			delete[] lineTable;
			lineTable = nullptr;
		}
		count = 0;

		if (rhs.count)
		{
			count = rhs.count;

			// allocate the same amount of space as the rhs.
			lineTable = new string[count];

			// deep copy
			for (size_t i = 0; i < count; i++)
			{
				lineTable[i] = rhs.lineTable[i];
			}
		}
		return *this;
	}


	// Move constructor
	Text::Text(Text && rhs) : count(0), lineTable(nullptr)
	{
		*this = move(rhs);
	}


	// Move assignment operator
	Text && Text::operator=(Text && rhs)
	{
		if (this != &rhs)
		{
			// delete our brains (if we have any)
			delete[] lineTable;

			// steal 'brains'
			count = rhs.count;
			lineTable = rhs.lineTable;

			// turn rhs into a 'zombie'
			rhs.count = 0;
			rhs.lineTable = nullptr;
		}
		return move(*this);
	}


	// Destructor
	Text::~Text()
	{
		delete[] lineTable;
		lineTable = nullptr;
	}


	// A member function named size_t size() const that returns the number of records of text data
	size_t Text::size() const
	{
		return count;
	}


	void Text::dump()
	{
		size_t num = count;

		if (num > 10) num = 10;

		for (size_t i = 0; i < num; i++)
		{
			cout << "	line " << i + 1 << " -->" << lineTable[i] << "<--" << endl;
			// i+1 to count from 1, not 0
		}
	}
}