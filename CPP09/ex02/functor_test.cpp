/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functor_test.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 12:17:42 by slambert          #+#    #+#             */
/*   Updated: 2026/11/04 13:59:04 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <deque>

struct Less
{
    bool operator()(int x, int y) const
    {
        std::cout << "x is: " << x << ", y is: " << y << std::endl;
        return x < y;
    }
};

struct IdxLess
{
    private:
        const std::vector<int> &_v;  
    public:
        IdxLess(const std::vector<int> &v): _v(v) {}
        bool operator()(int i, int j) const
        {
            return _v[i] < _v[j];
        }
};

template <typename T>
struct IndexValueLess
{
    private:
        const T &_v;
    public:
        int *_count;
        IndexValueLess(const T &v, int* count): _v(v), _count(count) {}
        bool operator()(int i, int j) const
        {
            ++(*_count);
            return _v[i] < _v[j];
        }
};

int main()
{
    // 1.
    {
        std::cout << "Test 1" << std::endl;
        Less l;
        std::cout << l(3,3) << std::endl;    
    }   

    // 2.
    {
        std::cout << "\nTest 2" << std::endl;
        std::vector<int> v;
        v.push_back(1);    
        v.push_back(3);    
        v.push_back(5);    
        v.push_back(7);
        std::vector<int>::iterator result = std::lower_bound(v.begin(), v.end(), 4, Less());
        std::cout << "Distance: " << std::distance(v.begin(), result) << std::endl;
    }
        
    // 3.
    {
        std::cout << "\nTest 3" << std::endl;
        std::vector<int> v;
        v.push_back(50);    
        v.push_back(10);    
        v.push_back(40);    
        v.push_back(20);
        v.push_back(30);
        
        //this simulates list a (sorted indices) 30 is still missing (index 4)
        std::vector<int> idx;
        idx.push_back(1);
        idx.push_back(3);
        idx.push_back(2);
        idx.push_back(0);
        
        std::vector<int>::iterator where_2_insert = std::lower_bound(idx.begin(), idx.end(), 4, IdxLess(v));
        idx.insert(where_2_insert, 4);
        for (std::vector<int>::iterator it = idx.begin(); it != idx.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
    }

        // 4.
    {
        std::cout << "\nTest 4" << std::endl;
        std::deque<int> v;
        v.push_back(50);    
        v.push_back(10);    
        v.push_back(40);    
        v.push_back(20);
        v.push_back(30);
        
        //this simulates list a (sorted indices) 30 is still missing (index 4)
        std::deque<int> idx;
        idx.push_back(1);
        idx.push_back(3);
        idx.push_back(2);
        idx.push_back(0);
        
        int count = 0;
        std::deque<int>::iterator where_2_insert = std::lower_bound(idx.begin(), idx.end(), 4, IndexValueLess<std::deque<int> >(v, &count));
        idx.insert(where_2_insert, 4);
        for (std::deque<int>::iterator it = idx.begin(); it != idx.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << "Count: " << count << std::endl;
    }
    
}
