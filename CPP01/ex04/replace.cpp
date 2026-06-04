/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 11:35:49 by slambert          #+#    #+#             */
/*   Updated: 2026/06/04 12:37:37 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"
#include <fstream>

// void actually_do_the_work (std::string s1, std::string s2)
// {
    
// }

/*
 * ifstream reads
 * ofstream creates and writes
 */
int replace_stuff(std::string filename, std::string s1, std::string s2)
{
    (void)s1;
    (void)s2;
    if (filename.empty())
    {
        std::cerr << "Filename can't be empty" << std::endl;
        return 1;
    }
    std::ifstream infile(filename.c_str());
    if (!infile)
    {
        std::cerr << "Infile could not be opened" << std::endl;
        return 1;
    }
    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile)
    {
        std::cerr << "Outfile could not be opened" << std::endl;
        return 1;
    }
    std::string buffer;
    /*PROBLEM: this approach does not handle \n correctly. if \n is in s1 or s2
      it stops working. 
      SOLUTION: read everything in 1 go, concat each read line to a bug buffer.
      only then execute the replacing logic.
    */
    while (std::getline(infile, buffer))
    {
        //read line is in the buffer
        //1. manipulate the buffer
        //2. write the buffer to the outfile
        outfile.write(buffer.c_str(), buffer.length());
        outfile.write("\n", 1);
    }
        //std::cout << buffer << std::endl;
    return 0;
}