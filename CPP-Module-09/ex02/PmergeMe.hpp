/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:45:32 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/23 18:59:52 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
#define PMERGEME_H

#include <iostream>
#include <vector>
#include <deque>
#include <sys/time.h>
#include <ctime>

class PmergeMe {
    private:
        std::vector<int> vec_num;
        std::deque<int> deq_num;
        int ac;
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &p);
        PmergeMe& operator=(const PmergeMe &p);
        
        PmergeMe(int ac, char **av);
        void Info_begin(int flag);
        void printtime(clock_t start_time, clock_t end_time, std::string cont);

        //Deque
        void mergeDeque(void);
        void mergeInsertionSort(std::deque<int>& values);
        void merge(std::deque<int>& left, std::deque<int>& right, std::deque<int>& result);

        //vector
        void mergeVector(void);
        void mergeInsertionSort(std::vector<int>& data, std::vector<int>& temp, int left, int right);
        void merge(std::vector<int>& data, std::vector<int>& temp, int left, int middle, int right);

};

#endif