#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

int main()
{
    int q;
    int num_comm;    

    std::string command;    

    std::vector<bool> queue;
    std::vector<int> worry_count;
//    std::vector<std::string> command;
//    std::vector<int> num_command;
    
    std::cin >> q;

    for(int i = 0; i < q; ++i)
    {
        std::cin >> command;
        
        if(command == "WORRY_COUNT")
        {   
            worry_count.push_back(std::count(queue.begin(), queue.end(), true));
        }
        else
        {
            std::cin >> num_comm;
            
            if(command == "COME" && num_comm > 0)
            {
                for(int j = 0; j < num_comm; ++j)
                    queue.push_back(false);
            }
            else if(command == "COME" && num_comm < 0)
            {
                for(int j = 0; j < -num_comm; ++j)
                    queue.pop_back();
            }
            else if(command == "WORRY")
                queue[num_comm] = true;
            else if(command == "QUIET")
                queue[num_comm] = false;
        }
    }

    for(auto elem : worry_count)
        std::cout << elem << std::endl;
        
    return 0;
}
