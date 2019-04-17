#include<iostream>

int main()
{
    int a = 0;
    int b = 0;
    int r = 0;

    std::cin >> a >> b;

    if(b > a)
    {
        a += b;
        b = a - b;
        a -= b;
    }
    
    while(a%b != 0)
    {
        r = a%b;
        a = b;
        b = r;        
    }

    if(r == 0)
        std::cout << b << std::endl;
    else 
        std::cout << r << std::endl;
 
    return 0;
}
