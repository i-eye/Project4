#ifndef STRING_VECTOR_H
#define STRING_VECTOR_H


#include <vector>
#include <string>
#include <iostream>

using namespace std;

class StringVector{
public:
	//constructors
	StringVector();
	StringVector(const StringVector& copy);
	~StringVector();

	int LinearSearch(string string);
	void AddUnsorted(string string);
	void Print();

	int BinarySearch(string search);
	int AddSorted(string value);

	vector<string>& getVectorCopy();

private:
	int BinarySearch(string search, int min, int max);
	int AddSorted(string value, int min, int max);
	vector<string> Vector;
};
#endif
