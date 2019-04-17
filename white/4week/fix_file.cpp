#include<iostream>
#include<fstream>
#include<iomanip>

int main()
{
    double value;
    std::ifstream input("input.txt");

    std::cout << std::fixed << std::setprecision(3);    

    while(input >> value)
    {  
        std::cout << value << std::endl;
    }

    return 0;
}
