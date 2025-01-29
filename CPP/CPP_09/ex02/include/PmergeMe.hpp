#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <iostream>
#include <ctime>
#include <stdexcept>

class PmergeMe {
public:
    PmergeMe() {} // default constructor
    PmergeMe(const std::vector<int>& vec);
    PmergeMe(const std::list<int>& lst);
    
    void mergeInsertSortVector(std::vector<int>& vec);
    void mergeInsertSortList(std::list<int>& lst);

    void sort(std::vector<int>& inputVec);
    void sort(std::list<int>& inputList);
    void sortAndDisplay(); // add this declaration

    void fordJohnsonSortVector(std::vector<int>& vec); // add this declaration
    void fordJohnsonSortList(std::list<int>& lst); // add this declaration

private:
    std::vector<int> vec;
    std::list<int> lst;
};

#endif // PMERGEME_HPP