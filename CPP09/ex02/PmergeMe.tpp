/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 17:40:05 by slambert          #+#    #+#             */
/*   Updated: 2026/11/10 16:38:57 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_TPP
#define PMERGE_ME_TPP

#include "PmergeMe.hpp"

//OCF required by subject because a struct is a class
template <typename T>
PmergeMe::IndexValueLess<T>::IndexValueLess():_v(NULL), _count(NULL) { }

template <typename T>
PmergeMe::IndexValueLess<T>::IndexValueLess(const T &v, int *count) : _v(v), _count(count) { }

template <typename T>
PmergeMe::IndexValueLess<T>::IndexValueLess::~IndexValueLess() { }

template <typename T>
PmergeMe::IndexValueLess<T>::IndexValueLess(const IndexValueLess &other): _v(other._v), _count(other._count) { }

template <typename T>
PmergeMe::IndexValueLess<T> &PmergeMe::IndexValueLess<T>::operator=(const IndexValueLess &other)
{
	if (this != &other)
	{
		_v = other._v;
		_count = other._count;
	}
	return *this;
}

template <typename T>
bool PmergeMe::IndexValueLess<T>::operator()(int i, int j) const
{
    ++(*_count);
    return _v[i] < _v[j];
}

template <typename T>
T PmergeMe::indices_2_values(T &con_val, T &con_ind)
{
	T ret_con;
	for (typename T::iterator it = con_ind.begin(); it != con_ind.end(); ++it)
		ret_con.push_back(con_val[*it]);
	return ret_con;
}

// Ford-Johnson (merge-insertion sort), always working with indices:
// 1. Create pairs of 2. Bigger num = winner, smaller num = loser. Store partner.
// 2. Winners go in a, losers in b.
// 3. If uneven, 1 element has no partner -> manually pushed to end of b.
// 4. Sort list a recursively.
// 5. Update b so it matches the changes done in 4.
// 6. Insert the losers (list b) into list a:
//   - Jacobsthal numbers: 1, 3, 5, 11, 21, ...
//   - Insertion sequence follows Jacobsthal: 1 -> 3 -> 2 -> 5 -> 4 -> 7 -> 6 (for 7 elements)
//   - (jump up to the next Jacobsthal number, then count down to the previous one)
//   - Each element gets inserted with binary search (by algorithm).
//   - Lower limit (iterator) = a.begin(), upper limit is the position of the partner,
//   - because we already did that comparison.
//	 - (element without partner has to check up to a.end() - whole list)
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
		++(*op_count);
		if (values[*index_it] > values[*(index_it + 1)])
			{ winner_index = *index_it;	loser_index = *(index_it + 1); }
		else
			{ winner_index = *(index_it + 1); loser_index = *index_it; }
		a.push_back(winner_index);
		b.push_back(loser_index);
		partners[winner_index] = loser_index;
		partners[loser_index] = winner_index;
	}
	if (ssize % 2 != 0)
		b.push_back(*(indices.end() - 1));
	a = sort_container(values, a, op_count);
	b = update_b(a, b, partners);
	loser_handler(a, b, partners, values, op_count);
	return a;
}

template <typename T>
T PmergeMe::update_b(T &a, T &b_old, T &partners)
{
	T b_new;
	for (typename T::iterator it = a.begin(); it != a.end(); ++it)
		b_new.push_back(partners[*it]);
	if (b_new.size() < b_old.size())
		b_new.push_back(b_old.back());
	return b_new;
}

// a. find partner index
// b. find partner iterator
// c. find where to insert
// d. actual insert
//we use smth called a functor here. because we work with the indices, we can not simply use
//the "normal" std::lower_bound with 3 arguments because it would simply compare the indices.
//What we actually want is to compare the values behind that indices. for that reason
//we use an overload of std::lower_bound that takes a Comparator as a 4th argument.

//The Comparator has to have this sig: bool pred(const Type1 &a, const Type2 &b)
//Type1 has to be the type that you get when you dereference the iterator
//Type2 is the type from the thing we want to compare to (b[i])
//(both types are int in our case)

//The thing is that we need the values list for that comparison.
//i created a struct that upon construction has a pointer to said values.
//overloading the ()operator actually enables the comparison.
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
		int partner_index = partners[b[i]];
		const typename T::iterator partner_iterator = std::find(a.begin(), a.end(), partner_index);
		const typename T::iterator insert_here = std::lower_bound(a.begin(), partner_iterator, b[i], IndexValueLess<T>(values, count));
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

#endif
