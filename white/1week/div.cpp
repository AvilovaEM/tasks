#include<iostream>

int main()
{
    int a = 0;
    int b = 0;
    
    std::cin >> a >> b;
    
    if(b == 0)
    {
        std::cout << "Impossible" << std::endl;
        return 0;
    }
    else
        std::cout << a/b << std::endl;
    
    return 0;
}
