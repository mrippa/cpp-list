
#ifndef LISTELEMENT_H
#define LISTELEMENT_H


class list_element {
    public:

        list_element(int n = 0, list_element* ptr = nullptr) 
            :data(n), next(ptr) {}

        friend ostream& operator<< (ostream& o, list_element*& le);
        //private:
        int data;
        list_element* next;
};
#endif
