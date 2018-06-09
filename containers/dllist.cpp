//
// Created by georg on 12/30/2017.
//
#include<iostream>
#include<cassert>
#include "../iterator/elem.h"

using namespace std;

template <typename T>
struct elem_dllist {
    T inf;
    elem_dllist<T>* next;
    elem_dllist<T>* prev;
};
template<typename T>
class DLList {
private:
    elem_dllist<T> *start;
    elem_dllist<T> *end;
    elem_dllist<T> *current;
    void copy(const DLList<T> &);
    void erase();
public:
    DLList();
    DLList(const DLList<T> &);
    ~DLList();
    DLList<T> &operator=(const DLList<T> &);
    void iterStart(elem_dllist<T> * = NULL);
    elem_dllist<T> *iter();
    elem_dllist<T>* getStart () const {
        return start;
    }
    elem_dllist<T>* getEnd () const {
        return end;
    }
    void push(const T &);
    void insertAfter(elem_dllist<T> *, const T &);
    void insertBefore(elem_dllist<T> *, const T &);
    void deleteElem(elem_dllist<T> *);
    void deleteAfter(elem_dllist<T> *);
    void deleteBefore(elem_dllist<T> *);
    int size() const;
    bool isEmpty() const;
    void print(std::ostream& os = std::cout) const;
};

template<typename T>
void DLList<T>::copy(const DLList<T> &other) {
    elem_dllist<T> *it = other.start;
    while (it) {
        push(it->inf);
        it = it->next;
    }
}

template<typename T>
void DLList<T>::erase() {
    while (start)
        deleteElem(start);
}

template<typename T>
DLList<T>::DLList() {
    start = end = NULL;
}

template<typename T>
DLList<T>::DLList(const DLList<T> &other) {
    start = end = NULL;
    copy(other);
}

template<typename T>
DLList<T>::~DLList() {
    erase();
}

template<typename T>
DLList<T> &DLList<T>::operator=(const DLList<T> &other) {
    if (this != &other) {
        erase();
        copy(other);
    }
    return *this;
}

template<typename T>
void DLList<T>::iterStart(elem_dllist<T> *p) {
    if (p == NULL)
        current = start;

    else current = p;
}

template<typename T>
elem_dllist<T> *DLList<T>::iter() {
    elem_dllist<T> *save = current;

    if (current)
        current = current->next;

    return save;
}

template<typename T>
void DLList<T>::push(const T &el) {
    if (end == NULL) {
        end = new elem_dllist<T>;
        assert(end != NULL);
        end->inf = el;
        end->prev = NULL;
        end->next = NULL;

        start = end;
    } else
        insertAfter(end, el);
}

template<typename T>
void DLList<T>::insertAfter(elem_dllist<T> *p, const T &el) {
    if (p == NULL) {
        cerr << "Error ! Trying to insert elem_dllistents after NULL !" << endl;
        return;
    }

    elem_dllist<T> *newelem_dllist = new elem_dllist<T>;
    assert(newelem_dllist != NULL);
    newelem_dllist->inf = el;
    newelem_dllist->prev = p;
    newelem_dllist->next = p->next;

    p->next = newelem_dllist;
    if (p != end)
        newelem_dllist->next->prev = newelem_dllist;

    else
        end = newelem_dllist;
}

template<typename T>
void DLList<T>::insertBefore(elem_dllist<T> *p, const T &el) {
    if (p == NULL) {
        cerr << "Error ! Trying to insert elem_dllistents before NULL !" << endl;
        return;
    } else if (p == start) {
        elem_dllist<T> *newelem_dllist = new elem_dllist<T>;
        assert(newelem_dllist != NULL);
        newelem_dllist->inf = el;
        newelem_dllist->prev = NULL;
        newelem_dllist->next = start;

        start->prev = newelem_dllist;
        start = newelem_dllist;
    } else {
        p = p->prev;
        insertAfter(p, el);
    }
}

template<typename T>
void DLList<T>::deleteElem(elem_dllist<T> *p) {
    if (p == NULL) {
        cerr << "Error ! Trying to delete NULL !" << endl;
        return;
    }

    if (start == end) {
        delete start;
        start = end = NULL;
        return;
    }

    elem_dllist<T> *savepprev = p->prev;
    elem_dllist<T> *savepnext = p->next;

    if (p == start) {
        savepnext->prev = NULL;
        start = savepnext;
    } else if (p == end) {
        savepprev->next = NULL;
        end = savepprev;
    } else {
        savepprev->next = savepnext;
        savepnext->prev = savepprev;
    }

    delete p;
}

template<typename T>
void DLList<T>::deleteAfter(elem_dllist<T> *p) {
    if (p == NULL) {
        cerr << "Error ! Trying to delete NULL !" << endl;
        return;
    }

    if (p == end) {
        cerr << "Error ! Trying to delete after the end of the list !" << endl;
        return;
    }

    p = p->next;
    deleteElem(p);
}

template<typename T>
void DLList<T>::deleteBefore(elem_dllist<T> *p) {
    if (p == NULL) {
        cerr << "Error ! Trying to delete NULL !" << endl;
        return;
    }

    if (p == start) {
        cerr << "Error ! Trying to delete before the start of the list !" << endl;
        return;
    }

    p = p->prev;
    deleteElem(p);
}

template<typename T>
int DLList<T>::size() const {
    elem_dllist<T> *it = start;
    int br = 0;

    while (it) {
        br++;
        it = it->next;
    }

    return br;
}

template<typename T>
bool DLList<T>::isEmpty() const {
    return start == NULL;
}

template<typename T>
void DLList<T>::print(std::ostream& os) const {
    elem_dllist<T> *it = start;
    os << "DLList:";
    while (it) {
        os << ' ' << it->inf;
        it = it->next;
    }
    os << std::endl;
}

