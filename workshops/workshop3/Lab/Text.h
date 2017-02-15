#pragma once

namespace w3
{
	class Text
	{
	private:
		size_t count;

	public:
		Text(const Text& rhs); // copy constructor
		Text& operator = (const Text& rhs); // copy assignment operator
		Text(Text&& rhs); // move constructor
		Text&& operator = (Text&& rhs); // move assignment operator
		~Text(); // destructor
		size_t size() const; // returns the number of records of text data
	}
}