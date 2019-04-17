#include<iostream>
#include<string>

bool IsPalindrom(std::string str)
{
    if(str.empty())
        return true;

    for(int i = 0; i < int(str.size())/2; i++)
        if(str[i] != str[str.size()-i-1])
            return false;
    return true;
}

/*
int main()
{
    std::string s;
    std::cin >> s;

    std::cout << IsPalindrom(s) << std::endl;
    
    return 0;
}
*/
