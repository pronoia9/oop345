#pragma once
/* KVList Template

Design and code a class template named KVList for managing lists of key-value pairs.  
The classes generated by your template contain two parallel arrays of dimension N - a key array of type K and a value array of 
type V.  K, V and N are template parameters, which the porgrammer who uses your template can specify.  Save your template in a 
header file named KVList.h. 

Your design includes the following member functions: */

template <typename K, typename V, typename N>
class KVList
{
private:
	K k[N];
	V v[N];
	K kDefault;
	V vDefault;
	size_t count;

public:
	// default constructor - adopts a safe empty state
	KVList() : count(0)
	{
	}

	//returns the number of entires in the key-value list
	size_t size() const
	{
		return count;
	}

	// returns an unmodifiable reference to the key of element i in the list
	const K& key(int i) const
	{
		if (i >= 0 && i < count) return k[i];
		//exit(3);
		return kDefault;
	}

	// returns an unmodifiable reference to the value of element i in the list
	const V& value(int i) const
	{
		if (i >= 0 && i < count) return v[i];
		//exit(4);
		return vDefault;
	}

	// adds a new element to the list if room exists and returns a reference to the current object, does nothing if no room exists
	KVList& add(const K& kk, const V& vv) 
	{
		if (count < N)
		{
			k[count] = kk;
			v[count] = vv;
			count++;
		}
		exit(5);
	}

	// returns the index of the first element in the list with a key equal to k - defaults to 0
	int find(const K& kk) const
	{
		for (size_t i = 0; i < count; i++)
		{
			if (k[i] == kk) return i;
		}
		return 0;
	}

	// replaces element i in the list with the key and value received and returns a reference to the current object
	KVList& replace(int i, const K& kk, const V& vv)
	{
		if (i >= 0 && i < count) 
		{
			k[i] = kk;
			v[i] = vv;
		}
	} 
}; // template class KVList