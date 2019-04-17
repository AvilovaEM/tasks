#include<iostream>
#include<vector>
#include<string>

void MoveStrings(std::vector<std::string>& source, std::vector<std::string>& destination)
{
    for(auto elem : source)
        destination.push_back(elem);
    
    source.clear();
}
/*
int main()
{

    std::vector<std::string> a(4);
    a  = {"3", "a", "b", "c"};
    std::vector<std::string> b(2);
    b = {"1", "c"};

    MoveStrings(a, b);
    std::cout << a.size() << " " << b.size() << std::endl;
    return 0;
}*/
