#include<iostream>
#include<string>
#include<vector>

bool IsPalindrom(std::string str)
{
    if(str.empty())
        return true;

    for(int i = 0; i < int(str.size())/2; i++)
        if(str[i] != str[str.size()-i-1])
            return false;
    return true;
};

std::vector<std::string> PalindromFilter(std::vector<std::string> words, int minLght)
{
    std::vector<std::string> result;
    for(int i = 0; i < int(words.size()); i++)
    {
        if(int(words[i].size()) >= minLght)
            if(IsPalindrom(words[i]))
                result.push_back(words[i]);            
    }
    
    return result;
}
/*
int main()
{
    std::vector<std::string> s;
    std::vector<std::string> t;
    int min;

    t = PalindromFilter(s, min);

    for(int i = 0; i < int(s.size()); i++)
        std::cout << t[i] << " ";

    std::cout << std::endl;
    
    return 0;
}*/
