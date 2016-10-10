
#ifndef LIST_H
#define LIST_H

#include "list_element.h"

class list {

    public:
        //Could use default ctor in the following line...
        list():
            lsize(0), 
            head(nullptr),
            cursor(nullptr)
            {
                cout<< "DC: "<< this <<endl;
            } //empty list
        list(const int* arr, int n);
        list(const list& lst);
        list_element& operator[](int position);
        //dtor
        ~list();

        list_element* deepCopy(list_element* other, list_element* previous);
        void prepend(int c);
        list_element* get_head(){return head;}
        int get_element(){return cursor->data;}
        void advance(){cursor = cursor->next;}
        void rprint(list_element* node);
        void print();
        void release();
        friend ostream& operator<< (ostream& o, list*& lst);

    private:
        int lsize;
        list_element* head; //head
        list_element* cursor; //head

};
#endif
