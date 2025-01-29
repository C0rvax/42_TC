#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>

// Remove this redundant constructor definition
// PmergeMe::PmergeMe() {
//     // default constructor implementation (if needed)
// }

PmergeMe::PmergeMe(const std::vector<int>& input) : vec(input) {}

PmergeMe::PmergeMe(const std::list<int>& input) : lst(input) {}

void PmergeMe::mergeInsertSortVector(std::vector<int>& vec) {
    if (vec.size() <= 1) return;

    size_t mid = vec.size() / 2;
    std::vector<int> left(vec.begin(), vec.begin() + mid);
    std::vector<int> right(vec.begin() + mid, vec.end());

    mergeInsertSortVector(left);
    mergeInsertSortVector(right);

    std::merge(left.begin(), left.end(), right.begin(), right.end(), vec.begin());
}

bool comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.second < b.second;
}

void PmergeMe::fordJohnsonSortVector(std::vector<int>& vec) {
    if (vec.size() <= 1) return;

    // Step 1: Pair up the elements
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < vec.size() - 1; i += 2) {
        if (vec[i] < vec[i + 1]) {
            pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
        } else {
            pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
        }
    }
    if (vec.size() % 2 != 0) {
        pairs.push_back(std::make_pair(vec.back(), vec.back()));
    }

    // Step 2: Sort the pairs by their larger elements
    std::sort(pairs.begin(), pairs.end(), comparePairs);

    // Step 3: Merge the pairs into the sorted vector
    std::vector<int> sortedVec;
    for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
        sortedVec.push_back(it->first);
    }
    for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
        sortedVec.push_back(it->second);
    }

    // Step 4: Insertion sort to finalize the sorting
    for (size_t i = 1; i < sortedVec.size(); ++i) {
        int key = sortedVec[i];
        int j = i - 1;
        while (j >= 0 && sortedVec[j] > key) {
            sortedVec[j + 1] = sortedVec[j];
            --j;
        }
        sortedVec[j + 1] = key;
    }

    vec = sortedVec;
}

bool comparePairsList(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.second < b.second;
}

void PmergeMe::fordJohnsonSortList(std::list<int>& lst) {
    if (lst.size() <= 1) return;

    // Step 1: Pair up the elements
    std::list<std::pair<int, int> > pairs;
    std::list<int>::iterator it = lst.begin();
    while (it != lst.end()) {
        int first = *it;
        ++it;
        if (it != lst.end()) {
            int second = *it;
            if (first < second) {
                pairs.push_back(std::make_pair(first, second));
            } else {
                pairs.push_back(std::make_pair(second, first));
            }
            ++it;
        } else {
            pairs.push_back(std::make_pair(first, first));
        }
    }

    // Step 2: Sort the pairs by their larger elements
    pairs.sort(comparePairsList);

    // Step 3: Merge the pairs into the sorted list
    std::list<int> sortedList;
    for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
        sortedList.push_back(it->first);
    }
    for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
        sortedList.push_back(it->second);
    }

    // Step 4: Insertion sort to finalize the sorting
    for (std::list<int>::iterator it = ++sortedList.begin(); it != sortedList.end(); ++it) {
        int key = *it;
        std::list<int>::iterator jt = it;
        while (jt != sortedList.begin() && *--jt > key) {
            std::list<int>::iterator next = jt;
            ++next;
            *next = *jt;
        }
        std::list<int>::iterator next = jt;
        ++next;
        *next = key;
    }

    lst = sortedList;
}

void PmergeMe::mergeInsertSortList(std::list<int>& lst) {
    if (lst.size() <= 1) return;

    std::list<int>::iterator mid = lst.begin();
    std::advance(mid, std::distance(lst.begin(), lst.end()) / 2);
    std::list<int> left(lst.begin(), mid);
    std::list<int> right(mid, lst.end());

    mergeInsertSortList(left);
    mergeInsertSortList(right);

    lst.clear();
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(lst));
}

void PmergeMe::sort(std::vector<int>& inputVec) {
    fordJohnsonSortVector(inputVec); // use Ford-Johnson sort instead of merge sort
}

void PmergeMe::sort(std::list<int>& inputList) {
    fordJohnsonSortList(inputList); // use Ford-Johnson sort instead of merge sort
}

void PmergeMe::sortAndDisplay() {
    // Sort using vector
    std::clock_t start = std::clock();
    mergeInsertSortVector(vec);
    std::clock_t end = std::clock();
    double vectorDuration = 1000000.0 * (end - start) / CLOCKS_PER_SEC;

    // Display results for vector
    std::cout << "Before: ";
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) std::cout << *it << " ";
    std::cout << std::endl << "After:  ";
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << vectorDuration << " us" << std::endl;

    // Sort using list
    start = std::clock();
    mergeInsertSortList(lst);
    end = std::clock();
    double listDuration = 1000000.0 * (end - start) / CLOCKS_PER_SEC;

    // Display results for list
    std::cout << "Before: ";
    for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it) std::cout << *it << " ";
    std::cout << std::endl << "After:  ";
    for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it) std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << lst.size() << " elements with std::list: " << listDuration << " us" << std::endl;
}