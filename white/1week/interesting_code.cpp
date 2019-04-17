#include <iostream>
#include <string>
#include <vector>
#include <algoritm>

int main()
{
    std::string s = "abcdef";
    std::vector<int> nums = {1, 2, 3, 5, 5, 6};

//Как можно перебирать элементы
    for (char c : s)
    {
        std::cout << c << " ";
    }

//Если не хотим завязываться на типе
    for (auto c : s)
    {
        std::cout << c << " ";
    }

//Количество какого-то числа в векторе
    int quantity = count(begin(nums), end(nums), 5);

//Сортировка
    sort(begin(nums), end(nums));
    
    return 0;
}
