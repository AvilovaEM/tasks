#include<iostream>

int main()
{
    int a = 0;
    int b = 0;
    
    std::cin >> a >> b;

    if(a%2 == 0)
        for(int i = a; i <= b; i = i+2)
            std::cout << i << " ";
    else
        for(int i = a+1; i <= b; i = i+2)
            std::cout << i << " ";
    
    std::cout << std::endl;
    
    return 0;
}
