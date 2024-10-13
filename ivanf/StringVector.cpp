#include "StringVector.h"


StringVector::StringVector() 
{

}
StringVector::StringVector(const StringVector &copy) 
{

}

StringVector::~StringVector() 
{

}

// Long way to search
int StringVector::LinearSearch(string string) 
{
	for (unsigned int i = 0; i < Vector.size(); i++)
		if (string == Vector.at(i))
			return i;
	return -1;
}

// Quick way to add but not sorted
void StringVector::AddUnsorted(string string) 
{
	Vector.push_back(string);
}

// Print every value
void StringVector::Print() 
{
	for (string s : Vector)
		cout << s << endl;
	
}


vector<string>& StringVector::getVectorCopy()
{
	return Vector;
}

// Quick way to search
int StringVector::BinarySearch(string search)
{
	return BinarySearch(search, 0, (int)Vector.size()-1);
}

// Internal Binary Search
int StringVector::BinarySearch(string search, int min, int max)
{
	int mid = ((min + max) / 2);
	//cout << "Mid:" << mid << endl;
	
	if (min > max)
		return -1;
	else if (search == Vector.at(mid))
		return mid;
	else if (search > Vector.at(mid))
		return BinarySearch(search, mid+1, max);
	else
		return BinarySearch(search, min, mid-1);
	
	//return 55;
}

// Quick way to add a value sorted(binary method)
int StringVector::AddSorted(string value)
{
	int index = BinarySearch(value);

	if (index == -1)
	{
		if (Vector.empty())
			Vector.push_back(value);
		else
			return AddSorted(value, 0, (int)Vector.size() - 1);
	}
	return index;
}

// Internal add sorted
int StringVector::AddSorted(string value, int min, int max)
{
	int mid = ((min + max) / 2);
	//cout << "Mid:" << Vector.at(mid) << endl;
	if (min > max)
		return -1;
	else if (value > Vector.at(mid)  && mid+1 != (int)Vector.size()  && value > Vector.at(mid + 1))
		return AddSorted(value, mid + 1, max);
	else if (value < Vector.at(mid) && mid != 0 && value < Vector.at(mid - 1))
		return AddSorted(value, min, mid - 1);
	else {
		if(value > Vector.at(mid))
		{
			Vector.insert(Vector.begin() + mid + 1, value);
			return mid + 1;
		}
		else
		{
			Vector.insert(Vector.begin() + mid, value);
			return mid;
		}
	}

}
