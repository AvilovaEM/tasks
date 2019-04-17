#include<iostream>
#include<map>
#include<set>
#include<string>

std::set<std::string> BuildMapValuesSet(const std::map<int, std::string>& m)
{
    std::set<std::string> res;
    for(auto key : m)
        res.insert(key.second);

    return res;
}
