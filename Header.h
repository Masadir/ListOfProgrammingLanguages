#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
using namespace std;

struct listOfLanguages {
    int year;
    string name;
    string creator;
};

struct list {
    listOfLanguages l;
    list* next;
};

void addElement(list** u, listOfLanguages& x);
void print(list* u);