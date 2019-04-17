#include<iostream>
#include<set>
#include<map>
#include<string>

int main()
{
    int cnt_stop = 0;
    int stop_cnt;
    int cmnd_cnt;
    std::set<std::string> stop_tmp;
    std::map<std::set<std::string>, int> num_stop;
    std::string stop_name;

    std::cin >> cmnd_cnt;
    
    for(int i = 0; i < cmnd_cnt; ++i)
    {
        std::cin >> stop_cnt;
        
        for(int j = 0; j < stop_cnt; ++j)
        {
            std::cin >> stop_name;
            stop_tmp.insert(stop_name);
        }
        
        if(num_stop.count(stop_tmp) == 0)
        {
            cnt_stop++;
            num_stop[stop_tmp] = cnt_stop;
            std::cout << "New bus " << cnt_stop << std::endl;
        }
        else
        {
            std::cout << "Already exists for " << num_stop[stop_tmp] << std::endl;
        }
        stop_tmp.clear();
    }
    return 0;
}
