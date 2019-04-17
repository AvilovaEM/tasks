#include<iostream>
#include<string>
#include<map>

std::string MaxLessThen(std::map<int, std::string> test, int find_key)
{
    for(auto cur = test.begin(); cur != test.end(); cur++)
    {
        if(cur->first > find_key)
        {
            cur--;
            return cur->second;
        }
    }
    
    return (--test.end())->second;
};

class Person
{
    public:
        void ChangeFirstName(int year, const std::string& first_name)
        {
            first_name_in_year[year] = first_name;
            //for(auto& item : first_name_in_year)
            //    std::cout << item.first << " " << item.second << std::endl;
        }

        void ChangeLastName(int year, const std::string& last_name)
        {   
            last_name_in_year[year] = last_name;
            //for(auto& item : last_name_in_year)
            //    std::cout << item.first << " " << item.second << std::endl;
        }

        std::string GetFullName(int year)
        {
            //std::string print_first_name;
            //std::string print_last_name;
            std::string for_print = "";
            //std::map<int, std::string>::iterator low_f_name;
            //std::map<int, std::string>::iterator low_l_name;
            std::string low_f_name;
            std::string low_l_name;

            if((first_name_in_year.empty() && last_name_in_year.empty()) || (first_name_in_year.begin()->first > year && last_name_in_year.begin()->first > year))
                return "Incognito";
    
            if(first_name_in_year.empty() || first_name_in_year.begin()->first > year)
            {
                low_l_name = MaxLessThen(last_name_in_year, year);
                for_print += low_l_name;
                for_print += " with unknown first name";
                return for_print;
            }

            if(last_name_in_year.empty() || last_name_in_year.begin()->first > year)
            {
                low_f_name = MaxLessThen(first_name_in_year, year);
                for_print += low_f_name;
                for_print += " with unknown last name";
                return for_print;
            }

        
            //low_f_name = first_name_in_year.upper_bound(year);
            //low_l_name = last_name_in_year.upper_bound(year);
            
            low_f_name = MaxLessThen(first_name_in_year, year);
            low_l_name = MaxLessThen(last_name_in_year, year);
            for_print += low_f_name;
            for_print += " ";
            for_print += low_l_name;

            return for_print;
            
            /*for(auto& item : first_name_in_year)
            {
                if(item.first <= year)
                {
                    if(item.first == year)
                    {
                        print_first_name = item.second;
                        break;
                    }
                    else
                    {
                        item--;
                        print_first_name = item.second;
                    }
                }
            }*/
        }
    private:
        std::map<int, std::string> first_name_in_year;
        std::map<int, std::string> last_name_in_year;        
};

