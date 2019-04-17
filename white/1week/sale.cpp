#include<iostream>

int main()
{
    double n = 0;
    double a = 0;
    double b = 0;
    double x = 0;
    double y = 0;

    std::cin >> n >> a >> b >> x >> y;
    
    if(n > b)
    {
        std::cout << n*(100 - y)/100 << std::endl;
        return 0; 
    }
    else if (n > a)
    {
        std::cout << n*(100 - x)/100 << std::endl;
        return 0;
    }
    else
    {
        std::cout << n << std::endl;
        return 0;
    }    
}
