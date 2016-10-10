
#include <iostream>
using namespace std;

#include "list_element.h"

ostream& operator<< (ostream& o, list_element*& le) {

    if (le == nullptr)
        o << "###" ;
    else
        o << le->data ; 

    return o;
}

