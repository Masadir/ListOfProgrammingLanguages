#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
using namespace std;

// structure with haracteristics of the data
struct listOfLanguages {
    int year;
    string name;
    string creator;
};

// pointers structure of next language
struct myList {
    listOfLanguages language;
    myList* next;
};

void consoleMenu();
void addElement(myList** u, listOfLanguages& x);
void readFromFile(myList* u);
void printElements(myList* u);
void elementCreation(myList** u, int year, string name, string creator);
inline bool isFileExist(const std::string& name);