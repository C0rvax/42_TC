#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib> // for std::atoi
#include <iterator> // for std::advance
#include "PmergeMe.hpp"

void displaySequence(const std::vector<int>& sequence) {
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i] << (i < sequence.size() - 1 ? " " : "");
    }
}

void displaySequence(const std::list<int>& sequence) {
    for (std::list<int>::const_iterator it = sequence.begin(); it != sequence.end(); ++it) {
        std::list<int>::const_iterator next_it = it;
        std::advance(next_it, 1);
        std::cout << *it << (next_it != sequence.end() ? " " : "");
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: Usage: ./PmergeMe {list of integer}" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::list<int> lst;

    for (int i = 1; i < argc; ++i) {
        int num = std::atoi(argv[i]); // use std::atoi
        if (num <= 0) {
            std::cerr << "Error: negative number" << std::endl;
            return 1;
        }
        vec.push_back(num);
        lst.push_back(num);
    }

    std::cout << "Before: ";
    displaySequence(vec);
    std::cout << std::endl;

    PmergeMe sorter; // create an instance of PmergeMe

    std::clock_t startVec = std::clock();
    sorter.sort(vec); // call sort method for vector
    std::clock_t endVec = std::clock();

    std::clock_t startList = std::clock();
    sorter.sort(lst); // call sort method for list
    std::clock_t endList = std::clock();

    std::cout << "After:  ";
    displaySequence(vec);
    std::cout << std::endl;

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: "
              << 1000000.0 * (endVec - startVec) / CLOCKS_PER_SEC << " us" << std::endl;

    std::cout << "Time to process a range of " << lst.size() << " elements with std::list: "
              << 1000000.0 * (endList - startList) / CLOCKS_PER_SEC << " us" << std::endl;

    return 0;
}