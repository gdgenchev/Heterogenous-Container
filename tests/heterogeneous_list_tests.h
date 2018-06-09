//
// Created by georg on 12/30/2017.
//

#ifndef HETEROGENEOUS_CONTAINER_HETERGENEOUS_LIST_TESTS_H
#define HETEROGENEOUS_CONTAINER_HETERGENEOUS_LIST_TESTS_H

#endif //HETEROGENEOUS_CONTAINER_HETERGENEOUS_LIST_TESTS_H

#include "UnitTestFramework.h"


bool odd (const int& x) {
    return x % 2 != 0;
}

bool even (const int& x) {
    return x % 2 == 0;
}
bool dividesBy20 (const int& x) {
    return x % 20 == 0;
}

TEST_CASE("HGList", HeterogeneousList_PopulateFromFileAndWriteToFile) {
    HeterogeneousList<int> lst;
    Assert::IsTrue(lst.populateContainerFromFile("input.txt"));
    for (int i = 1; i <= 10; i++) {
        Assert::IsTrue(lst.member(i));
    }

    lst.removeElementsIf(odd);
    lst.printToFile();

    Assert::IsTrue(lst.populateContainerFromFile("output.txt"));
    for (int i = 2; i <= 10; i+=2) {
        Assert::IsTrue(lst.member(i));
    }

    //not existing file
    Assert::IsFalse(lst.populateContainerFromFile("input1.txt"));
}

TEST_CASE("HGList", HeterogeneousList_Member) {
    HeterogeneousList<int> lst;
    Container<int>* container1 = new SimpleDLList<int>;
    container1->push(1);
    container1->push(2);
    container1->push(3);
    container1->push(4);
    lst.addContainer(container1);

    Container<int>* container2 = new SimpleQueue<int>;
    container2->push(5);
    container2->push(6);
    container2->push(7);
    container2->push(8);
    container2->member(7);
    lst.addContainer(container2);

    Container<int>* container3 = new SimpleStack<int>;
    container3->push(10);
    container3->push(11);
    container3->push(12);
    container3->push(13);
    lst.addContainer(container3);

    Assert::IsTrue(lst.member(1));
    Assert::IsTrue(lst.member(6));
    Assert::IsTrue(lst.member(10));
    Assert::IsFalse(lst.member(9));
}

TEST_CASE("HGList", HeterogeneousList_AddElementToSmallest) {
    HeterogeneousList<int> lst;
    Container<int>* container1 = new SimpleDLList<int>;
    container1->push(1);
    container1->push(2);
    container1->push(3);
    container1->push(4);
    lst.addContainer(container1);

    Container<int>* container2 = new SimpleQueue<int>;
    container2->push(5);
    container2->push(6);
    container2->push(7);
    container2->push(8);
    lst.addContainer(container2);

    Container<int>* container3 = new SimpleStack<int>;
    container3->push(30);
    container3->push(32);
    container3->push(34);
    container3->push(38);
    lst.addContainer(container3);

    lst.addElement(10);
    lst.addElement(11);
    lst.addElement(31);

    Assert::IsTrue(container1->member(10));
    Assert::IsTrue(container2->member(11));
    Assert::IsTrue(container3->member(31));
}

TEST_CASE("HGList", HeterogeneousList_Condition) {
    HeterogeneousList<int> lst;
    Container<int>* container1 = new SimpleDLList<int>;
    container1->push(2);
    container1->push(4);
    container1->push(6);
    container1->push(8);
    lst.addContainer(container1);

    Container<int>* container2 = new SimpleQueue<int>;
    container2->push(10);
    container2->push(12);
    container2->push(14);
    container2->push(16);
    lst.addContainer(container2);

    Container<int>* container3 = new SimpleStack<int>;
    container2->push(20);
    container2->push(22);
    container2->push(24);
    container2->push(26);
    lst.addContainer(container3);

    Assert::IsFalse (lst.isConditionValid(odd));
    Assert::IsTrue (lst.isConditionValid(even));
    Assert::IsTrue (lst.isConditionValid(dividesBy20));
}

TEST_CASE("HGList", HeterogeneousList_Sort) {
    HeterogeneousList<int> lst;
    Container<int>* container1 = new SimpleDLList<int>;
    container1->push(4);
    container1->push(2);
    container1->push(8);
    container1->push(6);
    lst.addContainer(container1);

    Container<int>* container2 = new SimpleQueue<int>;
    container2->push(10);
    container2->push(20);
    container2->push(14);
    container2->push(16);
    lst.addContainer(container2);

    Container<int>* container3 = new SimpleStack<int>;
    container3->push(10);
    container3->push(20);
    container3->push(14);
    container3->push(16);
    lst.addContainer(container3);
    lst.sort();
  // lst.printToFile();
}

TEST_CASE("HGList", HeterogeneousList_RemoveElementsIfCondition) {
    HeterogeneousList<int> lst;

    Container<int> *container1 = new SimpleDLList<int>;
    container1->push(42);
    container1->push(43);
    container1->push(44);
    container1->push(45);
    lst.addContainer(container1);

    Container<int> *container2 = new SimpleQueue<int>;
    container2->push(11);
    container2->push(20);
    container2->push(15);
    container2->push(16);
    lst.addContainer(container2);

    Container<int> *container3 = new SimpleStack<int>;
    container3->push(17);
    container3->push(22);
    container3->push(23);
    container3->push(30);
    lst.addContainer(container3);

    lst.removeElementsIf(odd);
    Assert::IsFalse(lst.member(43));
    Assert::IsFalse(lst.member(45));
    Assert::IsFalse(lst.member(11));
    Assert::IsFalse(lst.member(15));
    Assert::IsFalse(lst.member(17));
    Assert::IsFalse(lst.member(23));
}

TEST_CASE("HGList", HeterogeneousList_getIteratorForX) {
    HeterogeneousList<int> lst;

    Container<int> *container1 = new SimpleDLList<int>;
    container1->push(42);
    container1->push(43);
    container1->push(44);
    container1->push(45);
    lst.addContainer(container1);

    Container<int> *container2 = new SimpleQueue<int>;
    container2->push(11);
    container2->push(20);
    container2->push(15);
    container2->push(16);
    lst.addContainer(container2);

    Container<int> *container3 = new SimpleStack<int>;
    container3->push(17);
    container3->push(22);
    container3->push(23);
    container3->push(30);
    lst.addContainer(container3);
    lst.sort();
    Assert::IsTrue(*lst.getIteratorForX(20) == 20);
    Assert::IsTrue(*lst.getIteratorForX(23) == 23);
    Assert::IsTrue(*lst.getIteratorForX(42) == 42);
    Assert::IsTrue(lst.getIteratorForX(58) == Iterator<int>());
}

TEST_CASE("HGList", HeterogeneousList_IterateOverSortedContainersAndGetSortedList){
    HeterogeneousList<int> lst;

    Container<int> *container1 = new SimpleDLList<int>;
    container1->push(28);
    container1->push(30);
    container1->push(17);
    container1->push(6);
    lst.addContainer(container1);

    Container<int> *container2 = new SimpleQueue<int>;
    container2->push(56);
    container2->push(25);
    container2->push(17);
    container2->push(2);
    lst.addContainer(container2);

    Container<int> *container3 = new SimpleStack<int>;
    container3->push(17);
    container3->push(85);
    container3->push(3);
    container3->push(41);
    lst.addContainer(container3);
    lst.sort();

    std::list<int> ascending;
    lst.iterAscending(ascending);
    Assert::AreEqual(ascending.front(),6);
    ascending.pop_front();
    Assert::AreEqual(ascending.front(),17);
    ascending.pop_front();
    Assert::AreEqual(ascending.front(),28);
    ascending.pop_front();
    Assert::AreEqual(ascending.front(),30);
    ascending.pop_front();
    Assert::AreEqual(ascending.front(),56);
    ascending.pop_front();
    Assert::AreEqual(ascending.front(),85);
    ascending.pop_front();
    Assert::IsTrue(ascending.empty());
}

TEST_CASE("HGList", HeterogeneousList_IterateOverHeterogeneousList) {
    HeterogeneousList<int> lst;

    Container<int> *container1 = new SimpleDLList<int>;
    container1->push(1);
    container1->push(2);
    container1->push(3);
    container1->push(4);
    lst.addContainer(container1);

    Container<int> *container2 = new SimpleQueue<int>;
    container2->push(5);
    container2->push(6);
    container2->push(7);
    container2->push(8);
    lst.addContainer(container2);

    Container<int> *container3 = new SimpleStack<int>;
    container3->push(12);
    container3->push(11);
    container3->push(10);
    container3->push(9);
    lst.addContainer(container3);

    std::list<int> iterLst;
    lst.iter(iterLst);
    int size = iterLst.size();
    for (int i = 1; i <= size; i++) {
        Assert::AreEqual(iterLst.front(),i);
        iterLst.pop_front();
    }
    Assert::IsTrue(iterLst.empty());
}