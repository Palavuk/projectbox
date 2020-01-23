#pragma once
#include <vector>
#include <thread>
#include <iterator>
#include <task_5/merge_sort.h>


std::vector<std::thread> threads(std::thread::hardware_concurrency() - 1);

template<typename iter>
struct interval{
	iter first;
	iter last;
};

template<typename iterator>
std::vector<interval<iterator>> split(iterator first, iterator last, size_t dim) {
	size_t step = std::distance(first, last) / dim;
	std::vector<interval<iterator>> splitted;
	iterator start = first;
	for (size_t i = 0; i < dim; i += step){
		splitted.push_back( { std::next(start, step), std::next(start, std::min(dist, step * 2)) } );
		start = std::next(start, step);
	}
	return splitted;
}

template<class iterator>
void sort_thread(iterator first, iterator last) {
	std::vector<interval<iterator>> intervals = split(first, last, threads.size());
	for (int i = 0; i < intervals.size(); i++){
		interval<iterator> inter = intervals[i];
		threads[i] = std::thread([inter] () { merge_sort(inter.first, inter.last);});
	};
	for (int i = 0; i < threads.size(); i++){
		if (threads[i].joinable())
			threads[i].join();
	};
}
