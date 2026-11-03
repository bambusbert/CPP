/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 17:40:05 by slambert          #+#    #+#             */
/*   Updated: 2026/11/03 17:58:49 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename T>
T PmergeMe::indices_2_values(T &con_val, T &con_ind)
{
	T ret_con;
	for (typename T::iterator it = con_ind.begin(); it != con_ind.end(); ++it)
	{
		ret_con.push_back(con_val[*it]);
	}
	return ret_con;
}

// always work with the indices!
// 1. create pairs of 2, insert winner/loser indices in a and b
// 2. if odd put last elem in b
// 3. recursive sorting of the winners
// 4. handling of losers (b) - insert elem in list a (binary search from 0 up to the partner)
template <typename T>
T PmergeMe::sort_container(T &values, T &indices, int *op_count)
{
	int ssize = static_cast<int>(indices.size());
	if (ssize == 1)
		return indices;
	T a, b, partners;
	for (size_t i = 0; i < values.size(); i++)
		partners.push_back(-1);
	
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
	if (ssize % 2 != 0)
		b.push_back(*(indices.end() - 1));
	a = sort_container(values, a, op_count);
	loser_handler(a, b, partners, values, op_count);
	return a;
}

template <typename T>
void PmergeMe::loser_handler(T &a, T &b, T& partners, T& values, int* count)
{
	unsigned int cur_jacobsthal = 1;
	unsigned int prev_jacobsthal = 1;
	unsigned int count_elems = -1;
	unsigned int size_b = b.size();
	unsigned int i = 0;
	
	while (++count_elems < size_b)
	{
		i = update_index(count_elems, size_b, prev_jacobsthal, cur_jacobsthal);
		// a. find partner index
		int partner_index = partners[b[i]];
		// b. find partner iterator
		const typename T::iterator partner_iterator = std::find(a.begin(), a.end(), partner_index);
		// c. find where to insert
		const typename T::iterator insert_here = std::lower_bound(a.begin(), partner_iterator, b[i], IdxLessTemp<T>(values, count));
		// d. actual insert
		a.insert(insert_here, b[i]);
	}
}

template <typename T>
void PmergeMe::print_container(T &con)
{
	typename T::iterator it = con.begin();
	while (it != con.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}
