#include "Header.h"
#include <string.h>
#include <conio.h>

void print(list* u) {
    list* p = u;
    while (p) {
        cout << "Year: " << p->l.year << endl;
        cout << "Name: " << p->l.name << endl;
        cout << "Creator: " << p->l.creator << endl;
        p = p->next;
    }
}
