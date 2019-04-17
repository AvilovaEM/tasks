#include<iostream>
#include<vector>
int main()
{
    int n = 0;
    std::vector<int> bn = {};

    std::cin >> n;

    while(n >= 1)
    {
        bn.push_back(n%2);
        n /= 2;
    }
     
    for(int i = bn.size()-1; i >= 0; i--)
       std::cout << bn[i];
    std::cout << std::endl;

    return 0;
}
