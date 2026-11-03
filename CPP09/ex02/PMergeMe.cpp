/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 17:47:49 by slambert          #+#    #+#             */
/*   Updated: 2026/11/03 16:56:25 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

const int PMergeMe::_jacobsthal_arr[31] = {
	1, 3, 5, 11, 21, 43, 85, 171, 341, 683,
	1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051,
	1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485,
	178956971, 357913941, 715827883, 1431655765
};

PMergeMe::PMergeMe()
{
}

PMergeMe::~PMergeMe()
{
}

PMergeMe::PMergeMe(const PMergeMe &other) : _con_vec(other._con_vec), _con_deq(other._con_deq), _t_vec(other._t_vec), _t_deq(other._t_deq) {}

PMergeMe &PMergeMe::operator=(const PMergeMe &other)
{
	if (this != &other)
	{
		_con_deq.clear();
		_con_deq = other._con_deq;
		_con_vec.clear();
		_con_vec = other._con_vec;
		_t_deq = other._t_deq;
		_t_vec = other._t_vec;
	}
	return *this;
}

bool PMergeMe::validate_input_and_fill_containers(char **argv)
{
	long num;
	int i = 0;

	while (argv[++i])
	{
		char *end;
		errno = 0;
		num = std::strtol(argv[i], &end, 10);
		if (errno == ERANGE || *end != '\0' || num < 0 || num > __INT_MAX__)
			return false;
		_con_deq.insert(_con_deq.end(), static_cast<int>(num));
		_con_vec.insert(_con_vec.end(), static_cast<int>(num));
	}
	return true;
}

template <typename T>
T PMergeMe::indices_2_values(T &con_val, T &con_ind)
{
	T ret_con;
	for (typename T::iterator it = con_ind.begin(); it != con_ind.end(); ++it)
	{
		ret_con.push_back(con_val[*it]);
	}
	return ret_con;
}

void PMergeMe::sort_containers()
{
	struct timespec ts;
	long start, end;
	clock_gettime(CLOCK_REALTIME, &ts);
	start = ts.tv_nsec + ts.tv_sec * 1000 * 1000 * 1000;

	std::vector<int> vec_indices;
	for (int i = 0; i < static_cast<int>(_con_vec.size()); i++)
		vec_indices.push_back(i);
	vec_indices = sort_container(_con_vec, vec_indices);
	_con_vec = indices_2_values(_con_vec, vec_indices);
	clock_gettime(CLOCK_REALTIME, &ts);
	end = ts.tv_nsec + ts.tv_sec * 1000 * 1000 * 1000;
	_t_vec = (end - start);

	clock_gettime(CLOCK_REALTIME, &ts);
	start = ts.tv_nsec + ts.tv_sec * 1000 * 1000 * 1000;
	std::deque<int> deq_indices;
	for (int i = 0; i < static_cast<int>(_con_deq.size()); i++)
		deq_indices.push_back(i);
	deq_indices = sort_container(_con_deq, deq_indices);
	_con_deq = indices_2_values(_con_deq, deq_indices);
	clock_gettime(CLOCK_REALTIME, &ts);
	end = ts.tv_nsec + ts.tv_sec * 1000 * 1000 * 1000;
	_t_deq = (end - start);
}

unsigned int PMergeMe::next_jacobsthal(unsigned int num)
{
	unsigned int prev = 1;
	unsigned int cur = 1;
	
	while (cur < num)
	{
		unsigned int prev_save = prev;
		prev = cur;
		cur = 2 * prev_save + cur;
	}
	return cur;
}

//interesting this is not much faster than not hardcoded
unsigned int PMergeMe::next_jacobsthal_hardcoded(unsigned int num)
{
	const int* begin = _jacobsthal_arr;
	const int* end = _jacobsthal_arr + sizeof(_jacobsthal_arr) / sizeof (_jacobsthal_arr[0]);
	return *(std::lower_bound(begin, end, num));
}

unsigned int PMergeMe::update_index(unsigned int count_elems, unsigned int& prev_jacob, unsigned int &cur_jacob)
{
	static unsigned int c = 0;
	if (count_elems == 0)
		return 0;
	if (next_jacobsthal_hardcoded(count_elems) == count_elems)
	{
		c = 0;
		unsigned int prev_save = prev_jacob;
		prev_jacob = cur_jacob;
		cur_jacob = 2 * prev_save + cur_jacob;
		return cur_jacob - 1;
	}
	c++;
	return cur_jacob - c - 1;
}

// always work with the indices
// at the end sort indices
template <typename T>
T PMergeMe::sort_container(T &values, T &indices)
{
	// base case
	int ssize = static_cast<int>(indices.size());
	if (ssize == 1)
		return indices;
	T a, b, partners;
	for (size_t i = 0; i < values.size(); i++)
		partners.push_back(-1);
	// 1. create pairs of 2, insert winner/loser indices in a and b

	for (typename T::iterator index_it = indices.begin(); index_it < indices.end() - 1; std::advance(index_it, 2))
	{
		int winner_index, loser_index;
		if (values[*index_it] > values[*(index_it + 1)])
		{
			winner_index = *index_it;
			loser_index = *(index_it + 1);
		}
		else
		{
			winner_index = *(index_it + 1);
			loser_index = *index_it;
		}
		a.push_back(winner_index);
		b.push_back(loser_index);
		partners[winner_index] = loser_index; // i think i don't need that
		partners[loser_index] = winner_index;
	}
	// 1a. if odd put last elem in b
	if (ssize % 2 != 0)
		b.push_back(*(indices.end() - 1));
		
	// 2. recursive sorting of the winners
	a = sort_container(values, a);
	// 3. handling of losers (b) - insert elem in list a (binary search from 0 up to the partner)
	unsigned int cur_jacobsthal = 1;
	unsigned int prev_jacobsthal = 1;
	unsigned int count_elems = -1;
	
	unsigned int size_b = b.size();
	unsigned int i = 0;
	while (++count_elems < size_b)
	{
		i = update_index(count_elems, prev_jacobsthal, cur_jacobsthal);
		// a. find partner index
		int partner_index = partners[b[i]];
		// b. find partner iterator
		const typename T::iterator partner_iterator = std::find(a.begin(), a.end(), partner_index);
		// c. find where to insert
		int count = 0;
		const typename T::iterator insert_here = std::lower_bound(a.begin(), partner_iterator, b[i], IdxLessTemp<T>(values, &count));
		// d. actual insert
		a.insert(insert_here, b[i]);
	}
	return a;
}

template <typename T>
void PMergeMe::print_container(T &con)
{
	typename T::iterator it = con.begin();
	while (it != con.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

void PMergeMe::print_vec()
{
	print_container(_con_vec);
}

void PMergeMe::print_deq()
{
	print_container(_con_deq);
}

void PMergeMe::print_timings()
{
	std::cout << "Time to process a range of " << _con_vec.size()
			  << " elements with std::vector : " << _t_vec << " ns" << std::endl;
	std::cout << "Time to process a range of " << _con_vec.size()
			  << " elements with std::deque : " << _t_deq << " ns" << std::endl;
}

// void PMergeMe::sort_containers(double *t_vec, double *t_deq)
// {
// 	clock_t start, end;
// 	start = clock();
// 	_con_vec = sort_container(_con_vec, t_vec);
// 	end = clock();
// 	_t_vec = static_cast<double>(end - start) * CLOCKS_PER_SEC / 1000 / 1000;
// 	start = clock();
// 	_con_deq = sort_container(_con_deq, t_deq);
// 	end = clock();
// 	_t_deq = static_cast<double>(end - start) * CLOCKS_PER_SEC / 1000 / 1000;
// 	std::cout << "Time vec: " << _t_vec << std::endl;
// 	std::cout << "Time deq: " << _t_deq << std::endl;
// }

// template <typename T>
// bool PMergeMe::container_already_sorted(T &con_val, T &con_ind)
// {
// 	int ssize = con_ind.size();
// 	for (int i = 1; i < ssize; i++)
// 	{
// 		if (con_val[con_ind[i]] < con_val[con_ind[i - 1]])
// 			return false;
// 	}
// 	return true;
// }

// TODO put in tpp
// 0. start timer
// 1. split array into 2 smaller arrays
// 2. perform sort_container on these 2 arrays
// 3. merge these 2 arrays back into one
// 4. stop & set timer
// TODO this is standard merge sort (or divide-and-conquer). what we need to
// implement is the "Ford-Johnson" or "merge insert" algo.
// template <typename T> T PMergeMe::sort_container(T &con)
// {
// 	if (con.size() == 1)
// 		return con;
// 	typename T::iterator middle = con.begin();
// 	std::advance(middle, con.size() / 2);
// 	T left(con.begin(), middle);
// 	T right(middle, con.end());
// 	left = sort_container(left);
// 	right = sort_container(right);
// 	return merge_container(left, right);
// }

// problem: pop_front gibt es nur bei deque, nicht bei vector
// ich kann aber T::erase(T:begin()) verwenden
// template <typename T> T PMergeMe::merge_container(T &left, T &right)
// {
// 	T res;
// 	while (left.size() > 0 && right.size() > 0)
// 	{
// 		if (left.front() <= right.front())
// 		{
// 			res.insert(res.end(), left.front());
// 			left.erase(left.begin());
// 		}
// 		else
// 		{
// 			res.insert(res.end(), right.front());
// 			right.erase(right.begin());
// 		}
// 	}
// 	while (left.size() > 0)
// 	{
// 		res.insert(res.end(), left.front());
// 		left.erase(left.begin());
// 	}
// 	while (right.size() > 0)
// 	{
// 		res.insert(res.end(), right.front());
// 		right.erase(right.begin());
// 	}
// 	return res;
// }
