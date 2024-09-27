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


int StringVector::LinearSearch(string string) 
{
	for (int i = 0; i < Vector.size(); i++)
		if (string == Vector.at(i))
			return i;
	return -1;
}
void StringVector::AddUnsorted(string string) 
{
	Vector.push_back(string);
}
void StringVector::Print() 
{
	for (string s : Vector)
		cout << s << endl;
	
}

vector<string>& StringVector::getVectorCopy()
{
	return Vector;
}

int StringVector::BinarySearch(string search)
{
	return BinarySearch(search, 0, Vector.size()-1);
}

int StringVector::BinarySearch(string search, int min, int max)
{
	int mid = ((min + max) / 2);
	cout << "Mid:" << mid << endl;
	
	if (search == Vector.at(mid))
		return mid;
	else if (search > Vector.at(mid))
		return BinarySearch(search, mid, max);
	else if (search < Vector.at(mid))
		return BinarySearch(search, min, mid);
	
	return 55;
}