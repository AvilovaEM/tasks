#include<iostream>
#include<fstream>
#include<iomanip>

int main()
{
    int rows;
    int columns;
    int value;
    std::ifstream input("input.txt");

    input >> rows >> columns;
    
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < columns; ++j)
        {
            input >> value;
            std::cout << std::setw(10) << value;
            if(j != columns-1)
                std::cout << " ";
            input.ignore(1);
        }
        std::cout << std::endl;
    }
    
//    std::cout << std::endl;    
    
    return 0;    
}
