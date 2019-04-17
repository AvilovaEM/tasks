#include<iostream>
#include<string>

void EnsureEqual(const std::string& left, const std::string& right)
{
    std::string exc_text = left + " != " + right;
    if(left != right)
        throw std::runtime_error(exc_text);
}

