/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:45:29 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/23 18:59:21 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &p) {
    *this = p;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &p) {
    this->vec_num = p.vec_num;
    this->deq_num = p.deq_num;
    return *this;
}

PmergeMe::PmergeMe(int ac, char **av) {
    for(int i = 1; i < ac; i++) {
        int av_num = atoi(av[i]);
        if(av_num < 0) {
            std::cerr << "Error: Negative Numbers are forbidden" << std::endl;
            exit(EXIT_FAILURE);
        }
        vec_num.push_back(av_num);
    }
    this->ac = ac;
}

void PmergeMe::Info_begin(int flag) {
    if(flag == 0) 
        std::cout << "Before:  ";
    else if (flag == 1)
        std::cout << "After:   ";
    int count = 0;
    int s = vec_num.size();
    for(std::vector<int>::iterator i = vec_num.begin(); i != vec_num.end(); i++) {
        if(s <= 5)
            std::cout << *i << " ";
        else {
            count++;
            if(count <= 4)
                std::cout << *i << " ";
            if (count == 4)
                std::cout << "[...]" << std::endl;
        }
    }
    if (s <= 5)
        std::cout << std::endl;
    if(flag == 0)
        std::copy(vec_num.begin(), vec_num.end(), std::inserter(deq_num, deq_num.end()));
}
//vector

void PmergeMe::merge(std::vector<int>& data, std::vector<int>& temp, int left, int middle, int right) {
    int i = left, j = middle + 1, k = left;
    while (i <= middle && j <= right) {
        if (data[i] < data[j]) {
            temp[k++] = data[i++];
        } else {
            temp[k++] = data[j++];
        }
    }

    while (i <= middle) {
        temp[k++] = data[i++];
    }

    while (j <= right) {
        temp[k++] = data[j++];
    }

    for (k = left; k <= right; k++) {
        data[k] = temp[k];
    }
}

/* void    printData(std::vector<int>& data) {
    std::vector<int>::iterator it;
    for(it = data.begin(); it != data.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
} */

void PmergeMe::mergeInsertionSort(std::vector<int>& data, std::vector<int>& temp, int left, int right) {
    if (left < right) {
        if (right - left < 10) {
            for (int i = left + 1; i <= right; i++) {
                int key = data[i];
                int j = i - 1;
                while (j >= left && data[j] > key) {
                    data[j + 1] = data[j];
                    j--;
                }
                data[j + 1] = key;
                //printData(data);
            }
        } else {
            int middle = (left + right) / 2;
            mergeInsertionSort(data, temp, left, middle);
            mergeInsertionSort(data, temp, middle + 1, right);
            merge(data, temp, left, middle, right);
        }
    }
}

void PmergeMe::mergeVector(void) {
    clock_t start_time = clock();
    std::vector<int> temp(vec_num.size());
    mergeInsertionSort(vec_num, temp, 0, vec_num.size() - 1);
    clock_t end_time = clock();
    Info_begin(1);
    printtime(start_time, end_time, "vector : ");
}

//deque
void PmergeMe::merge(std::deque<int>& left, std::deque<int>& right, std::deque<int>& result) {
    while(!left.empty() && !right.empty()) {
        if (left.front() < right.front()) {
            result.push_back(left.front());
            left.pop_front();
        } else {
            result.push_back(right.front());
            right.pop_front();
        }
    }
    while(!left.empty()) {
        result.push_back(left.front());
        left.pop_front();
    }
    while(!right.empty()) {
        result.push_back(right.front());
        right.pop_front();
    }
}

void PmergeMe::mergeInsertionSort(std::deque<int>& values) {
    if(values.size() < 2){
        return;
    }

    std::deque<int> left, right, result;
    int middle = values.size() / 2;

    for (int i = 0; i < middle; ++i)
        left.push_back(values[i]);
    for (unsigned int i = middle; i < values.size(); ++i)
        right.push_back(values[i]);

    mergeInsertionSort(left);
    mergeInsertionSort(right);
    merge(left, right, result);
    std::copy(result.begin(), result.end(), values.begin());
}

void PmergeMe::printtime(clock_t start_time, clock_t end_time, std::string cont) {
    double elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000.0;
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::" << cont << elapsed_time << " us." << std::endl;
}

void PmergeMe::mergeDeque(void) {
    clock_t start_time = clock();
    mergeInsertionSort(deq_num);
    clock_t end_time = clock();
    printtime(start_time, end_time, "deque : ");
}