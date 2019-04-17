#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>

int main()
{
    int Q;
    
    std::cin >> Q;

    std::string command;
    std::map<std::string, std::vector<std::string>> bus_stop;
    std::vector<std::string> order_bus;

    for(int i_big = 0; i_big < Q; ++i_big)
    {
        std::cin >> command;
//        std::cout << "i am read command " << command << std::endl;

        if(command == "NEW_BUS")
        {
            std::string bus_name;
    	    std::string stop_name;
    	    std::vector<std::string> vect_tmp;
    		int stop_count;
        

            std::cin >> bus_name >> stop_count;
            order_bus.push_back(bus_name);

            for(int i = 0; i < stop_count; ++i)
            {
                std::cin >> stop_name;
                vect_tmp.push_back(stop_name);
            }

            bus_stop[bus_name] = vect_tmp;
        } else if (command == "BUSES_FOR_STOP")
        {
            std::string stop;
            bool stop_flg = false;
    
            std::cin >> stop;
    
            for(auto& item : order_bus)
            {
                std::vector<std::string>::iterator it;
                it = std::find((bus_stop[item]).begin(), bus_stop[item].end(), stop);
                if(it != bus_stop[item].end())
                {
                    stop_flg = true;
                    std::cout << item << " ";
                }    
            }

            if(!stop_flg)
                std::cout << "No stop";
            std::cout << std::endl;
            stop_flg = false;            
        } else if(command == "STOPS_FOR_BUS")
        {
            std::string bus;
            std::cin >> bus;
  //          std::cout << "in if" << std::endl;
            
            if(bus_stop.count(bus) > 0)
            {
                for(int i = 0; i < bus_stop[bus].size(); ++i)
                {
                    bool stop_flg = false;
    
                    std::cout << "Stop " << bus_stop[bus][i] << ": ";
                    for(auto& item : order_bus)
                    {
                        if(item != bus)
                        {
                        
                            std::vector<std::string>::iterator it;
                            it = std::find(bus_stop[item].begin(), bus_stop[item].end(), bus_stop[bus][i]);
                            if(it != bus_stop[item].end())
                            {
                                stop_flg = true;
                                std::cout << item << " ";
                            }
                        }
                    }
        
                    if(!stop_flg)
                        std::cout << "no interchange";
                    std::cout << std::endl;
                }
            }
            else
            {
                std::cout << "No bus" << std::endl;
            }
        } else if(command == "ALL_BUSES")
        {
            if(!bus_stop.empty())
            {
                for(auto& item : bus_stop)
                {
                    std::cout << "Bus " << item.first << ": ";
                    for(auto& stop : item.second)
                        std::cout << stop << " ";
                    std::cout << std::endl;
                }
            }
            else
            {
                std::cout << "No buses" << std::endl;
            }
        }
    }

    return 0;
}
