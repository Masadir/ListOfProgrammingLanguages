#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <string.h>
#include <conio.h>

void addElement(list** u, listOfLanguages& x) {
    list* p = new list;
    p->l.year = x.year;
    p->l.name = x.name;
    p->l.creator = x.creator;
    if (*u == 0) {
        p->next = 0;
        *u = p;
        return;
    }
    list* t = *u;
    if (t->l.year >= p->l.year) {
        p->next = t;
        *u = p;
        return;
    }
    list* t1 = t->next;
    while (t1) {
        if (t->l.year < p->l.year && p->l.year <= t1->l.year) {
            t->next = p;
            p->next = t1;
            return;
        }
        t = t1;
        t1 = t1->next;
    }
    t->next = p;
    p->next = 0;
}


auto createNewElement(int year, string name, string creator) {

    listOfLanguages test = {year, name, creator};

    return test;
    /*
     listOfLanguages language;
     language.name = name;
     language.creator = creator;
     language.year = year;
     return language;
     */
}

void readFromFile() {
    string line;
    ifstream file("C:\\Users\\Masadir\\Downloads\\listOfProgrammingLanguages.csv"); 
    if (file.is_open()) {
        while (getline(file, line)) {



           






            char arr[256];
            strcpy(arr, line.c_str());



            char* year = 0;
            year = strtok(arr, ";");




            string name;
            name = strtok(0, ";");
            string creator;
            creator = strtok(0, ";");
            cout << year << name << creator << endl;

        }
    }
    file.close();
    cout << "End of program" << endl; 
}


int main() {
    
    list* u = NULL;

    listOfLanguages elementForAdd = createNewElement(48, "Java", "Noname");

    addElement(&u, elementForAdd);
    print(u);
    //readFromFile();
}

