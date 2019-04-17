#include<iostream>
#include<string>

int main()
{
    std::string s = "";
    int flg = 0;

    std::cin >> s;
    
    for(int i = 0; i < int(s.size()); i++)
    {        
        if(s[i] == 'f' && flg == 1)
        {
            std::cout << i << std::endl;
            return 0;
        }
        else if(s[i] == 'f')
            flg = 1;
    }
       
    if(flg)
        std::cout << "-1" << std::endl;
    else 
        std::cout << "-2" << std::endl;

    return 0;
}
