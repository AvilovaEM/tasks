#include<iostream>
#include<map>
#include<string>

std::map<char, int> CountLetter(const std::string& word)
{
    std::map<char, int> cnt_lttr;

    for(char letter : word)
        ++cnt_lttr[letter];

    return cnt_lttr;
}

int main()
{
    int cnt_words;
    std::map<char, int> first_word;
    std::map<char, int> second_word;
    std::string frst_wrd;
    std::string scnd_wrd;
    
    std::cin >> cnt_words;
    
    for(int i = 0; i < cnt_words; ++i)
    {
        std::cin >> frst_wrd >> scnd_wrd;
        
        first_word = CountLetter(frst_wrd);
        second_word = CountLetter(scnd_wrd);

        if(first_word == second_word)
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
    }

    return 0;
}

