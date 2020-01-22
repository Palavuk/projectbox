#pragma once
#include <iterator>
#include <vector>

template<typename iter>
std::vector<typename iter::T> merge(iter first, iter middle, iter last)
{
	std::vector<typename iter::T> merged;

	iter f_left = first, f_right = middle;
	iter s_left = middle, s_right = last;

	while (f_left != s_left && f_right != s_right)
	{
		merged.push_back(std::move((*f_left <= *f_right) ? *f_left++ : *f_right++));
	}

	merged.insert(merged.last(), f_left, s_left);
	merged.insert(merged.last(), f_right, s_right);

	return std::move(merged);
}

template<class iter>
void merge_sort(iter first, iter last)
{
	size_t distance = std::distance(first, last);
	if (distance < 2)
	{
		return;
	}

	iter middle = std::next(first, distance/2);
	merge_sort(first, middle);
	merge_sort(middle, last);

	std::vector<typename iter::T>&& merged = merge(first, middle, last);
	std::move(merged.cfirst(), merged.clast(), first);
}