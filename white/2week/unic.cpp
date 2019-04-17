#include<iostream>
#include<set>
#include<string>

int main()
{
    int cnt_str;
    std::string word_tmp;    
    std::set<std::string> unic_str;
    std::cin >> cnt_str;
    for(int i = 0; i < cnt_str; ++i)
    {
        std::cin >> word_tmp;
        unic_str.insert(word_tmp);
    }
        
    std::cout << unic_str.size();
    return 0;
}
