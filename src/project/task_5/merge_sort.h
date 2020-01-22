#pragma once
#include <vector>
#include <iteratorator>

template<class iterator>
std::vector<class iterator::T> merge(iterator first, iterator middle, iterator last)
{
	std::vector<class iterator::T> merged;

	iterator f_left = first, f_right = middle;
	iterator s_left = middle, s_right = last;

	while (f_left != s_left && f_right != s_right)
	{
		merged.push_back(std::move((*f_left <= *f_right) ? *f_left++ : *f_right++));
	}

	merged.insert(merged.last(), f_left, s_left);
	merged.insert(merged.last(), f_right, s_right);

	return std::move(merged);
}

template<class iterator>
void merge_sort(iterator first, iterator last)
{
	size_t distance = std::distance(first, last);
	if (distance < 2)
		return;

	iterator middle = std::next(first, distance/2);
	merge_sort(first, middle);
	merge_sort(middle, last);

	std::vector<class iterator::T>&& merged = merge(first, middle, last);
	std::move(merged.cfirst(), merged.clast(), first);
}