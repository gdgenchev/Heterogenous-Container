//
// Created by georg on 12/30/2017.
//

#ifndef HETEROGENEOUS_CONTAINER_HETEROGENEOUSLIST_H
#define HETEROGENEOUS_CONTAINER_HETEROGENEOUSLIST_H

#include <iostream>
#include "containers/container.h"
#include "simple_containers/simple_queue.cpp"
#include "simple_containers/simple_stack.cpp"
#include "simple_containers/simple_dllist.cpp"
#include <list>
#include <fstream>
#include <sstream>
template <typename T>
class HeterogeneousList {
private:
    std::list<Container<T>*> lst;
public:
    bool populateContainerFromFile(std::string fileName);
    void addContainer(Container<T>* container);
    void print() const;
    bool member(const T& val) const;
    bool isConditionValid(Condition<T> condition);
    void removeElementsIf(Condition<T> condition);
    Iterator<T> begin() const;
    Iterator<T> getIteratorForX(const T& x);
    void iterAscending(std::list<T>& ascending);
    void iter(std::list<T>& lst);
    void addElement(const T& x);
    void sort();
    void printToFile(std::string outputFile = "output.txt");
};

template <typename T>
void HeterogeneousList<T>::addContainer(Container<T> *container) {
    lst.push_back(container);
}

template <typename T>
bool HeterogeneousList<T>::member(const T &val) const {
    for (Container<T>* container : lst) {
        if (container->member(val)){
            return true;
        }
    }
    return false;
}

template <typename T>
void HeterogeneousList<T>::addElement(const T &x) {
    Container<T>* minContainer = lst.front();
    for (Container<T>* container : lst) {
        if (container->size() < minContainer->size()) {
            minContainer = container;
        }
    }
    minContainer->push(x);
}

template <typename T>
bool HeterogeneousList<T>::populateContainerFromFile(std::string fileName) {
    std::ifstream inFile(fileName);
    if (!inFile.is_open()) {
        return false;
    }
    //int n;
    //inFile >> n;
    //inFile.ignore();
    std::string line;
    while (std::getline(inFile, line))
    {
        std::istringstream iss(line);
        std::string typeOfContainer;
        iss >> typeOfContainer;
        int element;
        Container<T> *container;
        if (typeOfContainer == "DLList:") {
            container = new SimpleDLList<T>;

        }else if (typeOfContainer == "Queue:") {
            container = new SimpleQueue<T>;
        } else if (typeOfContainer == "Stack:") {
            container = new SimpleStack<T>;
        } else {
                return false;
        }
        while (iss >> element) {
            container->push(element);
        }
        addContainer(container);
    }
    return true;
}

template<typename T>
bool HeterogeneousList<T>::isConditionValid(Condition<T> condition) {
    for (Container<T> *container : lst) {
        if (container->isConditionValid(condition)) {
            return true;
        }
    }
    return false;
}

template<typename T>
void HeterogeneousList<T>::sort() {
    for (Container<T>* container : lst) {
        container->sort();
    }
}

template<typename T>
void HeterogeneousList<T>::removeElementsIf(Condition<T> condition) {
    for (Container<T>* container : lst) {
        container->removeElementsIf(condition);
    }
}

template <typename T>
void HeterogeneousList<T>::print() const {
    std::cout << "The heterogeneous container consists of:\n";
    for (const Container<T>* container : lst) {
        container->print();
    }
}


template<typename T>
void HeterogeneousList<T>::printToFile(std::string outputFile) {
    std::ofstream outFile(outputFile);

    for (Container<T>* container : lst) {
        container->print(outFile);
    }
}

template<typename T>
Iterator<T> HeterogeneousList<T>::getIteratorForX(const T &x) {
    Iterator<T> it;
    for (Container<T>* container : lst) {
        //skip checking container if last element of sorted is less than x
        if (*container->getLast() >= x) {
            if (container->getIteratorForX(x, it)) {
                return it;
            }
        }
    }
    return it;
}

template<typename T>
void HeterogeneousList<T>::iterAscending(std::list<T>& ascending) {
    Iterator<T> maxIt = begin(); // first element of first container
    ascending.push_back(*maxIt);
    for (Container<T>* container : lst) {
        Iterator<T> it(container->getFirst());
        if (*it > *maxIt) {
            ascending.push_back(*it);
        }
        while (it.valid()) {
            if (*maxIt > *it.next()) {
                ++it;
            } else {
                ascending.push_back(*it.next());
                ++it;
                maxIt = it;
            }
        }
    }
}

template<typename T>
void HeterogeneousList<T>::iter(std::list<T> &iterLst) {
    for (Container<T>* container: lst) {
        Iterator<T> it(container->getFirst());
        while (it.valid()) {
            iterLst.push_back(*it);
            ++it;
        }
    }
}

template<typename T>
Iterator<T> HeterogeneousList<T>::begin() const {
    return Iterator<T>(lst.front()->getFirst());
}

#endif //HETEROGENEOUS_CONTAINER_HETEROGENEOUSLIST_H
