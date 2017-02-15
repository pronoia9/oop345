// Workshop 3 - Copy and Move Semantics
// Text.h

#pragma once

#include <iostream>

namespace w3
{
	class Text
	{
	private:
		size_t count;
		std::string* lineTable;

	public:
		Text();
		Text(char* f);
		Text(const Text& rhs);              // copy constructor
		Text& operator = (const Text& rhs); // copy assignment operator
		Text(Text&& rhs);                   // move constructor
		Text&& operator = (Text&& rhs);     // move assignment operator
		~Text();                            // destructor
		size_t size() const;                // member function size_t size() const
		void dump();
	};
}