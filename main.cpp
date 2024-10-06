// Project3.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include "list6.h"
#include "StringVector.h"
#include <time.h>

using namespace std;

// all files that are in Books folder
string fileNames[] = {
//    "Dang",
    "AnneGables",
    "CallWild",
    "Copperfield",
//    "Dracula",
//    "Emma",
    "GreatExpectations",
//    "GrimmTales",
//    "Hound",
//    "Huckelberry",
//    "JekyllHyde",
    "JungleBook"};

// books folder and filetype
const string FOLDER = "Books/";
const string FILETYPE = ".txt";


// convert a string to only have alphabetical characters
static string to_word(string& String) {
    string returnString;
    for (char c : String) {
        if (isalpha(c)) {
            returnString += c;
        }
    }
    return returnString;
}

// convert a string to only have lowercase letters
static string to_lower(string& String) 
{
    string returnString;
    for (char c : String) {
        returnString += tolower(c);
    }
    return returnString;
}


// use a filename to create a new list with it
void read_file_linked_list(string name)
{
    // Get start time
    clock_t time1 = clock();

    // Some chunk of code
    List list = List();
    int count = 0;

    ifstream stream = ifstream(FOLDER + name + FILETYPE);
    if (stream.fail()) {
        cout << "Failed to open file:    " << FOLDER << name << FILETYPE << endl;
        return;
    }
    string var;
    while (stream >> var) {
        count++;
        var = to_lower(var);
        var = to_word(var);
        list.SortedInsert(var);
    }
    // Get end time(before printing anything)
    clock_t time2 = clock();
    double run_time = (time2 - time1) / (double)CLOCKS_PER_SEC;
    cout << "Input File Path:        " << FOLDER << name << FILETYPE << endl;
    cout << "Number of unique words: " << list.Size() << endl;
    cout << "Number of total words:  " << count << endl;
    cout << "Run time:               " << run_time << " seconds\n";
}

void read_file_vector_linear(string name)
{
    // Get start time
    clock_t time1 = clock();

    // Some chunk of code
    StringVector list = StringVector();
    int count = 0;

    ifstream stream = ifstream(FOLDER + name + FILETYPE);
    if (stream.fail()) {
        cout << "Failed to open file:    " << FOLDER << name << FILETYPE << endl;
        return;
    }
    string var;
    while (stream >> var) {
        count++;
        var = to_lower(var);
        var = to_word(var);
        if (list.LinearSearch(var) == -1)
            list.AddUnsorted(var);
    }
    // Get end time(before printing anything)
    clock_t time2 = clock();
    double run_time = (time2 - time1) / (double)CLOCKS_PER_SEC;
    cout << "Input File Path:        " << FOLDER << name << FILETYPE << endl;
    cout << "Number of unique words: " << list.getVectorCopy().size() << endl;
    cout << "Number of total words:  " << count << endl;
    cout << "Run time:               " << run_time << " seconds\n";
}

void read_file_vector_binary(string name)
{
    // Get start time
    clock_t time1 = clock();

    // Some chunk of code
    StringVector list = StringVector();
    int count = 0;

    ifstream stream = ifstream(FOLDER + name + FILETYPE);
    if (stream.fail()) {
        cout << "Failed to open file:    " << FOLDER << name << FILETYPE << endl;
        return;
    }
    string var;
    while (stream >> var) {
        count++;
        var = to_lower(var);
        var = to_word(var);
        list.AddSorted(var);
    }
    // Get end time(before printing anything)
    clock_t time2 = clock();
    double run_time = (time2 - time1) / (double)CLOCKS_PER_SEC;
    cout << "Input File Path:        " << FOLDER << name << FILETYPE << endl;
    cout << "Number of unique words: " << list.getVectorCopy().size() << endl;
    cout << "Number of total words:  " << count << endl;
    cout << "Run time:               " << run_time << " seconds\n";
}

int main()
{
    
    for (string name : fileNames) {
        std::cout << "Using linked list:\n";
        read_file_linked_list(name);
        std::cout << "\nUsing inefficient vector methods:\n";
        read_file_vector_linear(name);
        std::cout << "\nUsing effecient vector methods:\n";
        read_file_vector_binary(name);
        cout << endl;
        
    }
    
}

