#include<iostream>
#include<string>

int main()
{
    std::string a = "";
    std::string b = "";
    std::string c = "";

    std::cin >> a >> b >> c;

    if((a <= b && c <= a) || (b <= a && c <= b)) 
    {
        std::cout << c << std::endl;
        return 0;
    }

    if((c <= b && a <= c) || (b <= c && a <= b)) 
    {
        std::cout << a << std::endl;
        return 0;
    }

    if((a <= c && b <= a) || (c <= a && b <= c)) 
    {
        std::cout << b << std::endl;
        return 0; 
    }
}
