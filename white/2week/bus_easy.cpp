#include<iostream>
#include<map>
#include<vector>
#include<string>

int main()
{
    int cmnd_cnt;
    int stop_cnt;
    int num_bus_max = 0;
    std::string bus_stop;
    std::vector<std::string> bus_stop_tmp;
    std::map<std::vector<std::string>, int> num_bus;

    std::cin >> cmnd_cnt;
    for(int i = 0; i < cmnd_cnt; ++i)
    {
        std::cin >> stop_cnt;

        for(int j = 0; j < stop_cnt; ++j)
        {
            std::cin >> bus_stop;
            bus_stop_tmp.push_back(bus_stop);
        }
        
        if(num_bus.find(bus_stop_tmp) == num_bus.end())
        {
            num_bus_max++;
            num_bus[bus_stop_tmp] = num_bus_max;
            std::cout << "New bus " << num_bus_max << std::endl;
        }   
        else
        {   
            std::cout << "Already exists for " << num_bus[bus_stop_tmp] << std::endl;
        }
        bus_stop_tmp.clear();
    }

    return 0;
}
