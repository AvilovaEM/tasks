#include<iostream>
#include<algorithm>
#include<string>
#include<locale>
#include<vector>

std::string lower(const std::string& word)
{
    std::string word_in_func = word;
    std::transform(word_in_func.begin(), word_in_func.end(), word_in_func.begin(), ::tolower);
    return word_in_func;    
}

bool comp(const std::string& word1, const std::string& word2)
{
    std::string word1_tmp = word1;
    std::string word2_tmp = word2;

    if(lower(word1_tmp) < lower(word2_tmp))
        return true;
    else 
        return false;
}

int main()
{
    std::vector<std::string> sort_str;
    int n;

    std::cin >> n;
    sort_str.resize(n);

    for(int i = 0; i < n; ++i)
        std::cin >> sort_str[i];
    
    std::sort(sort_str.begin(), sort_str.end(), comp);

    for(int i = 0; i < n; ++i)
        std::cout << sort_str[i] << " ";
    std::cout << std::endl;

    return 0;
}
