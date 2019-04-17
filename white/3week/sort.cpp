#include<iostream>
#include<vector>
#include<algorithm>

bool comp(int i, int j)
{   
    if(i < 0) i = -i;
    if(j < 0) j = -j;
    return i < j;
}

int main()
{
    int n;
    std::cin >> n;
    int tmp;
    std::vector<int> vect;

    for(int i = 0; i < n; ++i)
    {
        std::cin >> tmp;
        vect.push_back(tmp);
    }

    sort(vect.begin(), vect.end(), comp);

    for(int i = 0; i < n; ++i)
        std::cout << vect[i] << " ";
    std::cout << std::endl;


    return 0;
}
