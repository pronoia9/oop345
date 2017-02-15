// g++ std=c++11 w3.cpp -o w3
#pragma once

#include <iostream>
#include <fstream>
#include <string>

namespace w3
{
	class Text
	{
	private:
		
	public:
		//
		void dump()
		{
			size_t number = count;

			if(number > 10) number = 10;

			for(size_t i = 0; i < number; i++)
			{
				std::cout << "	line " << i+1 << " -->" << lineTable[i] << "<--" << endl;
				// i+1 to count from 1, not 0
			}
		}
		

		// creates a 'zombie'
		Text() : count(0), lineTable(nullptr)
		{
			//
		}


		Text(char* f)
		{
			//
			if()
			{
				//
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
			std::cout << "copy =op this/lineTable=" << (void*)this << "/" << (void*)lineTable << " rhs/rhs.lineTable=" << (void*)&rhs << "/" << (void*)rhs.lineTable;
			if (this != &rhs)
			{
				delete [] lineTable;
				lineTable = nullptr;
				count = 0;

				// deep copy
				count = rhs.count;
				lineTable = new std::string [ count ];
				for (size_t i = 0; i < count; i++)
				{
					lineTable[i] = rhs.lineTable[]i;
				}

				return *this;
			}
		}


		Text&& operator= (Text&& rhs)
		{
			if (this != &rhs)
			{
				delete [] lineTable;

				// move pointer+count (steal brains)
				lineTable = rhs.lineTable;
				count = rhs.count;

				// turn rhs into a zombie
				rhs.lineTable = nullptr;
				rhs.count = 0;

				return std::move(*this);
			}
		}


		Text(const Text& rhs) : count(0), lineTable(nullptr)
		{
			*this = rhs;
		}


		Text(Text&& rhs) : count(0), lineTable(nullptr)
		{
			*this = std::move(rhs);
		}
	};
}