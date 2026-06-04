/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 11:35:49 by slambert          #+#    #+#             */
/*   Updated: 2026/06/04 19:20:37 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"
#include <fstream>

void find_and_replace (const std::string& s1, const std::string& s2, std::string& buffer)
{
    if (s1.empty())
        return;
    size_t i;
    i = buffer.find(s1, 0);
    while (i != std::string::npos)
    {
        buffer.erase(i, s1.length());
        buffer.insert(i, s2);
        i = buffer.find(s1, i + s2.length());
    }
}

int replace_stuff(std::string filename, std::string s1, std::string s2)
{
    if (filename.empty())
    {
        std::cout << "Filename can't be empty" << std::endl;
        return 1;
    }
    std::ifstream infile(filename.c_str());
    if (!infile)
    {
        std::cout << "Infile could not be opened" << std::endl;
        return 1;
    }
    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile)
    {
        std::cout << "Outfile could not be opened" << std::endl;
        return 1;
    }
    std::string line;
    std::string buffer = "";
    while (std::getline(infile, line))
    {
        buffer += line;
        if (!infile.eof())
            buffer += "\n";
    }
    find_and_replace(s1, s2, buffer);
    outfile << buffer;
    return 0;
}
