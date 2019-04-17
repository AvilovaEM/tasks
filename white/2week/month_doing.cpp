#include<iostream>
#include<vector>
#include<string>

int main()
{
    std::vector<std::vector<std::string>> list_doing(31);
    std::vector<int> day_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int cnt_cmmnd;
    int curr_month = 0;
  //  int next_
    std::string command;

    std::cin >> cnt_cmmnd;

    for(int i = 0; i < cnt_cmmnd; ++i)
    {
        std::cin >> command;
        
        if(command == "ADD")
        {
            std::string doing_name;
            int day;
            
            std::cin >> day >> doing_name;

            list_doing[day-1].push_back(doing_name); 
        } else if (command == "NEXT")
        {
            int next_month = (curr_month + 1)%12;
            
            //num_of_month = (num_of_month+1)%12;
            //поправить переход декабрь -> январь
            //if(day_in_month[num_of_month] > day_in_month[(num_of_month+1)%12])
            //{
                        
            for(int j = day_in_month[curr_month]-1; j >= day_in_month[next_month]; --j)
            {
//                std::cout << list_doing[j].size() << std::endl;

                for(int k = 0; k < list_doing[j].size(); ++k)
                {
//                    std::cout << "loop" << std::endl;
//                    std::cout << "j = " << j << " k = " << k << std::endl;
//                    std::cout << "list_doing[" << day_in_month[curr_month]-1 << "].push_back(" <<list_doing[j][k] << ")" << std::endl;
                    list_doing[day_in_month[next_month]-1].push_back(list_doing[j][k]);
                }
            }
                
                //list_doing.insert(end(list_doing)-(day_in_month[num_of_month]-day_in_month[num_of_month]), begin(list_doing)+day_in_month[num_of_month], end(list_doing));
            //}
//            std::cout << "end of for" << std::endl;  
            list_doing.resize(day_in_month[next_month]);
            curr_month = next_month;
            
            
        } else if(command == "DUMP")
        {
            int day;
            
            std::cin >> day;

            std::cout << list_doing[day-1].size() << " ";
            
            for(int j = 0; j < list_doing[day-1].size(); ++j)
            {
                std::cout << list_doing[day-1][j] << " ";
            }            

            std::cout << std::endl;
        }
    }

    return 0;         
}
