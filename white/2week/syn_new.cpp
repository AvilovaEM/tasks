#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

int main()
{
    int cmnd_cnt;
    std::map<std::string, std::string> alf_word;
    std::map<std::string, int> cnt_word;
    std::string word1;
    std::string word2;
    std::string command;

    std::cin >> cmnd_cnt;

    for(int i = 0; i < cmnd_cnt; ++i)
    {
        std::cin >> command;

        if(command == "ADD")
        {
            std::cin >> word1 >> word1;

            if(word1 > word2)
                std::swap(word1, word2);
            
            alf_word[word1] = word2;
            ++cnt_word[word1];
            ++cnt_word[word2];   
        }
        else if(command == "COUNT")
        {
            std::cin >> word1;
            std::cout << cnt_word[word1] << std::endl;
        }
        else if(command == "CHECK")
        {
            std::cin >> word1 >> word2;
    
            if(word1 > word2)
                std::swap(word1, word2);
            
        }
    }
    
}
