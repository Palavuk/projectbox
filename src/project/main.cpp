#include <iostream>
#include <vector>

#include "task_5/merge_sort.h"


int main() {
	std::vector<int> vec;
	for (int i = 10; i > 1; i--)
		vec.push_back(i);
	
	std::cout<<*vec.begin()<<" "<<*vec.end()<<std::endl;
    merge_sort(vec.begin(), vec.end());
	std::cout<<*vec.begin()<<" "<<*vec.end()<<std::endl;

	return 0;
}