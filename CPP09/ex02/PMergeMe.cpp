/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 17:47:49 by slambert          #+#    #+#             */
/*   Updated: 2026/10/26 17:22:52 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

PMergeMe::PMergeMe()
{
}

PMergeMe::~PMergeMe()
{
}

PMergeMe::PMergeMe(const PMergeMe &other)
{
	_con_deq = other._con_deq;
	_con_vec = other._con_vec;
}

PMergeMe &PMergeMe::operator=(const PMergeMe &other)
{
	if (this != &other)
	{
		_con_deq.clear();
		_con_deq = other._con_deq;
		_con_vec.clear();
		_con_vec = other._con_vec;
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
		//std::cout << num << std::endl;
	}
	return true;
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

void PMergeMe::sort_containers()
{
	struct timespec ts;
	long start, end;
	clock_gettime(CLOCK_REALTIME, &ts);
	start = ts.tv_nsec + ts.tv_sec * 1000 * 1000 * 1000;
	_con_vec = sort_container(_con_vec);
	clock_gettime(CLOCK_REALTIME, &ts);
	end = ts.tv_nsec + ts.tv_sec * 1000 * 1000 * 1000;
	_t_vec = (end - start);

	clock_gettime(CLOCK_REALTIME, &ts);
	start = ts.tv_nsec + ts.tv_sec * 1000 * 1000 * 1000;
	_con_deq = sort_container(_con_deq);
	clock_gettime(CLOCK_REALTIME, &ts);
	end = ts.tv_nsec + ts.tv_sec * 1000 * 1000 * 1000;
	_t_deq = (end - start);
	// std::cout << "Time vec: " << _t_vec << " ns" << std::endl;
	// std::cout << "Time deq: " << _t_deq << " ns" << std::endl;
}

// TODO put in tpp
// 0. start timer
// 1. split array into 2 smaller arrays
// 2. perform sort_container on these 2 arrays
// 3. merge these 2 arrays back into one
// 4. stop & set timer
template <typename T> T PMergeMe::sort_container(T &con)
{
	if (con.size() == 1)
		return con;
	typename T::iterator middle = con.begin();
	std::advance(middle, con.size() / 2);
	T left(con.begin(), middle);
	T right(middle, con.end());
	left = sort_container(left);
	right = sort_container(right);
	return merge_container(left, right);
}

// problem: pop_front gibt es nur bei deque, nicht bei vector
// ich kann aber T::erase(T:begin()) verwenden
template <typename T> T PMergeMe::merge_container(T &left, T &right)
{
	T res;
	while (left.size() > 0 && right.size() > 0)
	{
		if (left.front() <= right.front())
		{
			res.insert(res.end(), left.front());
			left.erase(left.begin());
		}
		else
		{
			res.insert(res.end(), right.front());
			right.erase(right.begin());
		}
	}
	while (left.size() > 0)
	{
		res.insert(res.end(), left.front());
		left.erase(left.begin());
	}
	while (right.size() > 0)
	{
		res.insert(res.end(), right.front());
		right.erase(right.begin());
	}
	return res;
}

template <typename T> void PMergeMe::print_container(T &con)
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
	std::cout	<< "Time to process a range of " << _con_vec.size() 
				<< " elements with std::vector : " << _t_vec << " ns" << std::endl;
	std::cout	<< "Time to process a range of " << _con_vec.size() 
				<< " elements with std::deque : " << _t_deq << " ns" << std::endl;
}
