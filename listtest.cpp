#include <iostream>

using namespace std;
#include "list.h"

int main() {

    list* mylist = new list();

    //char a = 't';

    mylist->prepend(10);
    mylist->prepend(100);
    cout << "Hello World1 " << mylist << endl;
    mylist->print();

    mylist->rprint(mylist->get_head());

    cout << "Hello World\n" << endl;

    delete mylist;

    list a,b;

    a.prepend(-3);
    a.prepend(9);
    a.prepend(8);
    a.prepend(2);
    cout << "*******list a********" << endl;
    a.print();
    
    cout << "*******list k********" << endl;
    list k(a);
    k.print();

    int data[10] = {3,4,6,7,-3,5};
    list d(data, 6);
    list e(data, 10);

//    for(int i=0; i<40; ++i)
//        b.prepend(i * i);

    cout << "*******list b********" << endl;
    b.print();

    cout << "*******list c********" << endl;
    list c(b);
    c.print();

    cout << "*******list e********" << endl;
    e.print();

    cout << "*******list d********" << endl;
    d.print();
    cout << endl;
    cout << endl;
    cout << endl;
    //list d(data, 10);
}

