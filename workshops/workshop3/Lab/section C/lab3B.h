#pragma once

#include <iostream>
#include <fstream>
#include <string>

//using namespace std;
namespace w3
{
	class Text
	{
	private:
		size_t count; // number of lines in the file
		std::string* lineTable; // table of lines

	public:
		void dump();
		{
			size_t number = count;
			if (number > 10) number = 10;
			for(size_t i = 0; i < number; i++)
			{
				std::cout << "	line " << i << ": -->" << lineTable[i] << "<--" << endl;
			}
		}

		size_t size() const
		{
			return count;
		}

		Text() : count(0), lineTable(nullptr)
		{
			//
		}

		Text(char* f) : count(0), lineTable(nullptr)
		{
			std::fstream in(f, std::ios::in);

			if (in.is_open())
			{
				std::string line;

				// count the lines
				while(getline(in, line))
					count++;

				std::cout << "File '" << f << "' contains " << count << " lines" << endl;

				lineTable = new std::string [ count ];

				{
					cout << in.good() << "<-- good: true if none of the flags is set" << endl;
					cout << in.fail() << "<-- fail: true if ios::failbit or ios::badbit is true" << endl;
					cout << in.eof()  << "<-- eof : true if ios::eof is true" << endl;
					cout << in.bad()  << "<-- bad : true if ios::badbit is true" << endl;
				}
				in.clear(); // reset the EOF state
				{
					cout << "after clearing the EOF state" << endl;
					cout << in.good() << "<-- good: true if none of the flags is set" << endl;
					cout << in.fail() << "<-- fail: true if ios::failbit or ios::badbit is true" << endl;
					cout << in.eof()  << "<-- eof : true if ios::eof is true" << endl;
					cout << in.bad()  << "<-- bad : true if ios::badbit is true" << endl;
				}

				// position the file at the beginning
				in.seekp(0); // offset 0 from the beginning is the beginning

				for (size_t i = 0; i < count; i++)
				{
					getline(in, lineTable[i]);
					auto cr = lineTable[i].find( '\r' );
					if(cr != std::string::npos)
					{
						lineTable[i].erase( cr ); 
					}
				}

				in.close();

				dump();
			}
			else
			{
				std::cerr << "Cannot open file '" << f << "'" << endl;
				exit(3);
			}
		}

		Text& operator = (const Text& rhs)
		{
			if (this != &rhs)
			{
				delete [] lineTable;
				lineTable = nullptr;
				count = 0;

				if(rhs.count)
				{
					count = rhs.count;

					// allocate the same amount of space as the rhs.
					lineTable = new std::string [ count ];

					// deep copy
					for(size_t i = 0; i < count; i++)
					{
						lineTable[i] = rhs.lineTable[i];
					}
				}
			}
			return *this;
		}

		Text&& operator = (Text&& rhs)
		{
			if (this != &rhs) 
			{
				// delete our brains (if we have any)
				delete [] lineTable;

				// steal 'brains'
				count = rhs.count;
				lineTable = rhs.lineTable;

				// turn rhs into a 'zombie'
				rhs.count = 0;
				rhs.lineTable = nullptr;
			}
			return move(*this);
		}

		Text(const Text& rhs) : count(0), lineTable(nullptr)
		{
			*this = rhs;
		}

		Text(Text&& rhs) : count(0), lineTable(nullptr)
		{
			*this = std::move(rhs);
		}

	}; // class Text
} // namespace w3