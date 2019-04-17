#include<iostream>
#include<vector>

int main()
{
    int N;
    int sum_temp = 0;
    int tmp_temp;
    int cnt_mean = 0;

    std::cin >> N;
    
    std::vector<int> temperature(N);
    std::vector<bool> mask_temp(N, false);

    for(int i = 0; i < N; ++i)
    {
        std::cin >> tmp_temp;
        sum_temp += tmp_temp;
        temperature[i] = tmp_temp;
    }

    sum_temp /= N;

    for(int i = 0; i < N; ++i)
    {
        if(temperature[i] > sum_temp)
        {
            cnt_mean++;
            mask_temp[i] = true;
        }    
    }

    std::cout << cnt_mean << std::endl;
    
    for(int i = 0; i < N; ++i)
    {
        if(mask_temp[i] == true)
            std::cout << i << " ";
    }

    std::cout << std::endl;
    
    return 0;
}
