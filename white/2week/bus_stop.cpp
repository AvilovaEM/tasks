#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>

int main()
{
    int command_cnt;
    int stop_cnt;
    std::string bus;
    std::string stop_name;
    std::string command;
    std::vector<std::string> bus_stop;
    std::map<std::string, std::vector<std::string> > bus_list;
    bool is_find_flg = false;

    std::cin >> command_cnt;

    for(int i = 0; i < command_cnt; ++i)
    {
        std::cin >> command;
        
        if(command == "NEW_BUS")
        {
            std::cin >> bus;
            std::cin >> stop_cnt;

            for(int j = 0; j < stop_cnt; j++)
            {   
                std::cin >> stop_name;
                bus_stop.push_back(stop_name);
            }
            bus_list[bus] = bus_stop;
        }
        else if(command == "BUSES_FROM_STOP")
        {
            std::cin >> stop_name;
            
            for(const auto& bus_tmp : bus_list)
            {
                if(find(bus_tmp.second.begin(), bus_tmp.second.end(), stop_name) != bus_tmp.second.end())
                { 
                    is_find_flg = true;                       
                    std::cout << bus_tmp.first << " ";                
                }
                 
            }

            if(!is_find_flg)
                std::cout << "No stop";
            
            std::cout << std::endl;
            is_find_flg = false;            
        }
    }
    
    

/*
    for(const auto& bus_tmp : bus_list)
    {
        std::cout << bus_tmp.first << " ";
        
        for(int i = 0; i < bus_tmp.second.size(); ++i)
            std::cout << bus_tmp.second[i] << " ";
        std::cout << std::endl;
    }
*/
    return 0;
}
