#include "../containers/container.h"

template <typename T>
class SimpleDLList : public Container<T>, public DLList<T> {
public:
    bool member(const T& x) {
        DLList<T>::iterStart();
        elem_dllist<T> *it = DLList<T>::iter();
        while (it != nullptr) {
            if (it->inf == x) {
                return true;
            }
            it = DLList<T>::iter();
        }
        return false;
    }

    void push(const T& x) {
        DLList<T>::push(x);
    }

    void pop() {
        DLList<T>::iterStart();
        elem_dllist<T>* start = DLList<T>::iter();
        DLList<T>::deleteElem(start);
    }

    Iterator<T> getFirst() {
        return Iterator<T>((elem<T>*)DLList<T>::getStart());
    }

    Iterator<T> getLast() {
        return Iterator<T>((elem<T>*)DLList<T>::getEnd());
    }

    //object slicing
    bool getIteratorForX(const T& x,Iterator<T>& itX) {
        Iterator<T> it((elem<T>*) DLList<T>::getStart());
        while (it.valid()) {
            if (*it == x) {
                itX = it;
                return true;
            }
            ++it;
        }
        return false;
    }

    void removeElementsIf(Condition<T> condition) {
        DLList<T>::iterStart();
        elem_dllist<T> *it = DLList<T>::iter();
        while (it != nullptr) {
            if (condition(it->inf)) {
                DLList<T>::deleteElem(it);
            }
            it = DLList<T>::iter();
        }
    }

    int size() const {
        return DLList<T>::size();
    }

    void sort() {
        std::vector<T> v;
        DLList<T>::iterStart();
        elem_dllist<T>* it = DLList<T>::iter();
        while (it) {
            v.push_back(it->inf);
            it = DLList<T>::iter();
        }
        std::sort(v.begin(), v.end());
        DLList<T>::~DLList();
        for (int i = 0; i < v.size(); i++) {
            DLList<T>::push(v[i]);
        }
    }

    bool isConditionValid(Condition<T> condition) {
        DLList<T>::iterStart();
        elem_dllist<T> *it = DLList<T>::iter();
        while (it != nullptr) {
            if (condition(it->inf)) {
                return true;
            }
            it = DLList<T>::iter();
        }
        return false;
    }

    void print(std::ostream& os) const {
        DLList<T>::print(os);
    }
};