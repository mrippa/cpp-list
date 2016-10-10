#include <iostream>
using namespace std;

#include "list.h"

list_element* list::deepCopy(list_element* other, list_element* previous) {

    if (other == nullptr)
        return nullptr;

    //test the contents of other...
    cout << "Before: <new,prev>=<" << other<<"," << previous << ">" << endl;

    //deep copy here ...
    //... chain and create
    list_element* newnode = new list_element();
    newnode->data = other->data;   //new data element becomes old data element
    previous->next = newnode;      //update previous element next member to point here
    other = other->next;           //advance: current node to cursor = cursor->next
    previous = newnode;            //previous element = this new element

    //test the contents of other...
    cout << "After: <new,prev>=<" << other<<"," << previous << ">" << endl;

    newnode->next = deepCopy(other, previous);
    return newnode;
}

ostream& operator<< (ostream& o, list*& lst) {

    list_element* h = lst->head;
    while (h != nullptr) {
        o << h->data << ", " ;
        h = h->next;
    }
    o << "###" << endl;
    return o;
}
list_element& list::operator[](int position) {

    list_element* h = head;
    for(int i=0; i != position; h=h->next)
       if ( h == nullptr)
           break;

    return *h;
}

void list::rprint(list_element* node) {

    if (node == nullptr) {
        cout << "###" << endl;
        return;
    }
    else {
        cout << node->data << ", ";
        rprint(node->next);
    }
}

// Prepend will check where head is pointing
//   to see if the list is empty. If the list
//   is empty, create a new list_element where
//   head AND cursor point to it.
//
//   Otherwise, create a new list_element where
//   only head points to it. In this case, cursor
//   will still be pointing to previous list_element,
//   as it has not been advanced!
//
//   So, once prepend finishes, head is guaranteed to
//   point to a new list_element, but cursor is only
//   updated if the list was previously empty.
void list::prepend(int n) {

    if ( head == nullptr )//empty list
        cursor = head = new list_element(n, head);
    else
        head = new list_element(n, head);
    lsize++;
}

//Copy constructor
list::list(const list& lst) {

    if(lst.head == nullptr) {
        head = nullptr; cursor = nullptr;
    }
    else {
        cursor = lst.head;
        list_element* h = new list_element();
        list_element* previous;
        head = h;
        h->data = lst.head->data;
        previous = h;
        //advance();

//        for(; cursor != nullptr; ) {
//            //deep copy here ...
//            //... chain and create
//            h = new list_element();
//            h->data = get_element(); //new data element becomes old data element
//            previous->next = h;      //update previous element next member to point here
//            advance();               //advance: cursor = cursor->next
//            previous = h;            //previous element = this new element
//            lsize++;
//        }
//
        cursor = deepCopy(cursor->next, previous);
        cursor = head;//cursor points back head
    }
    //cout << "copy constructor of "<< &lst << " into "<< this << endl;
}

//converting constructor in c++11
list::list(const int* arr, int n) {

    list_element* h = new list_element(); 
    list_element* previous; 
    head = cursor = h;  //assign head and cursor to new element.
    h->data = arr[0];   //new data = old data
    previous = h;       //previous element = new element

    for(int i=0; i<n; ++i) {
        h = new list_element();  //new element
        h->data = arr[i];        //new data = old data
        previous->next = h;      //update previous element next member to point here
        advance();               //advance this currsor to point to next
        //cursor = cursor->next;
        previous = h;
        lsize++;
    }

    cursor = head; //cursor points back head
}

list::~list() {
    cout << "destructor called on "<< this << endl;
    release(); // march thru and delete list elements
}

//TODO: Not complete...
void list::release() {

    for(cursor = head; cursor != nullptr;) {
        cursor = head->next;
        delete head;
        head = cursor;
    }
    cout << "Fini" << endl;
}

void list::print() {

    list_element* h = head;
    while( h != nullptr) {
        cout << h->data << ", ";
        h=h->next;
    }

    cout << "###" << endl;
}

