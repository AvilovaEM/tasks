#include<iostream>
#include<vector>
#include<algorithm>

std::vector<int> Reversed(const std::vector<int>& vect)
{
    std::vector<int> vect_rev = vect;

    std::reverse(std::begin(vect_rev), std::end(vect_rev)); 

    return vect_rev;
}
