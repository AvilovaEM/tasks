#include<iostream>
#include<string>
#include<set>
#include<map>
#include<algorithm>

int main()
{
    int cmnd_cnt;
    std::string word1;
    std::string word2;
    std::string command;
    std::map<std::string, std::set<std::string> > map_syn;
 //   bool in_set_flg = false;

    std::cin >> cmnd_cnt;
    
    for(int i = 0; i < cmnd_cnt; ++i)
    {
        std::cin >> command;
        
        if(command == "ADD")
        {
            std::cin >> word1 >> word2;

            map_syn[word1].insert(word2);
            map_syn[word2].insert(word1);         
        }
        else if(command == "COUNT") 
        {
            int word_cnt = 0;
            std::cin >> word1;
            if(map_syn.count(word1) > 0)
            {
                word_cnt = map_syn[word1].size();    
            }
            
            std::cout << word_cnt << std::endl;
        }
        else if(command == "CHECK")
        {
            std::cin >> word1 >> word2;
            if((map_syn.count(word1) > 0 && map_syn[word1].find(word2) != map_syn[word1].end()) ||
               (map_syn.count(word2) > 0 && map_syn[word2].find(word1) != map_syn[word2].end()))
                std::cout << "YES" << std::endl;
            else
                std::cout << "NO" << std::endl;
           
        }       
    }

    return 0;
}
