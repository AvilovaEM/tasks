#include<iostream>
#include<cmath>

int main()
{
    double a = 0;
    double b = 0;
    double c = 0;
    double D = 0;

    std::cin >> a >> b >> c;

    if(a == 0)
    {
        if(b != 0)
        {
            std::cout << -c/b << std::endl;
            return 0;
        }
        else
            return 0;
    }    
    
    D = b*b - 4*a*c;

    if(D > 0)
    {
        std::cout <<  (-b + sqrt(D))/(2*a) << " " << (-b - sqrt(D))/(2*a) << std::endl;
        return 0;
    }
    else 
    {
        if(D == 0)
        {
            std::cout << (-b)/(2*a);
            return 0;
        }
            
    }

    return 0;
}
