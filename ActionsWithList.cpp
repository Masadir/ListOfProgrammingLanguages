#include "Header.h"

// print elements of list from the beginning
void printElements(myList* u) {
    myList* listElement = u;
    while (listElement) {
        cout << "Year: " << listElement->language.year << endl;
        cout << "Name: " << listElement->language.name << endl;
        cout << "Creator: " << listElement->language.creator << endl;
        cout << endl;
        listElement = listElement->next;
    }
}

// add new element in to a correct place in a list depending on its year of creation
void addElement(myList** u, listOfLanguages& x) {
    myList* incomingElement = new myList;
    incomingElement->language.year = x.year;
    incomingElement->language.name = x.name;
    incomingElement->language.creator = x.creator;
    if (*u == 0) {
        incomingElement->next = 0;
        *u = incomingElement;
        return;
    }
    myList* nextToIncomingElement = *u;
    if (nextToIncomingElement->language.year >= incomingElement->language.year) {
        incomingElement->next = nextToIncomingElement;
        *u = incomingElement;
        return;
    }
    myList* thirdAfterIncomingElement = nextToIncomingElement->next;
    while (thirdAfterIncomingElement) {
        if (nextToIncomingElement->language.year < incomingElement->language.year && incomingElement->language.year <= thirdAfterIncomingElement->language.year) {
            nextToIncomingElement->next = incomingElement;
            incomingElement->next = thirdAfterIncomingElement;
            return;
        }
        nextToIncomingElement = thirdAfterIncomingElement;
        thirdAfterIncomingElement = thirdAfterIncomingElement->next;
    }
    nextToIncomingElement->next = incomingElement;
    incomingElement->next = 0;
}

// transform dates from file in to a new element of list
void elementCreation(myList** u, int year, string name, string creator) {
    listOfLanguages elementForAdd = {year, name, creator};
    addElement(u, elementForAdd);
}
