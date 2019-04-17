#include<iostream>
#include<string>
#include<map>
#include<vector>

int main()
{
    int Q;
    
    std::cin >> Q;
    std::map<std::string, std::vector<std::string>> sinonim;
    
    for(int i = 0; i < Q; ++i)
    {
        std::string command;
        std::cin >> command;
        
        if(command == "ADD")
        {
            std::string word1;
            std::string word2;
            
            std::cin >> word1 >> word2;
            sinonim[word1].push_back(word2);
            sinonim[word2].push_back(word1);            
        } else if(command == "COUNT")
        {
            std::string word;
            
            std::cout << sinonim[word].size() << std::endl;
        } else if(command == "CHECK")
        {
            std::string word1;
            std::string word2;
            bool find_flg = false;
            std::cin >> word1 >> word2;

            for(int j = 0; j < sinonim[word1].size(); ++j)
            {
                if(sinonim[word1][j] == word2)
                {
                    find_flg = true;
                    std::cout << "YES" << std::endl;
                }
            }
            
            if(!find_flg)
                std::cout << "NO" << std::endl;
            
        }
    }
    return 0;
}
