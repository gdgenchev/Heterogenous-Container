#include "heterogeneous_list.cpp"
#include "tests/heterogeneous_list_tests.h"
int main() {

   // RunTests();
    HeterogeneousList<int> heterogeneousList;
    heterogeneousList.populateContainerFromFile("input.txt");
  //  std::cout << heterogeneousList.member(10);
    heterogeneousList.print();

    return 0;
}
