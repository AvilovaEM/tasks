#include<iostream>
#include<string>
#include<map>

int main()
{
    int cnt_cmmnd;
    std::string command;
    std::string country;
    std::string new_capital;
    std::string old_country_name;
    std::string new_country_name;
    std::map<std::string, std::string> country_capital;

    std::cin >> cnt_cmmnd;

    for(int i = 0; i < cnt_cmmnd; ++i)
    {
        std::cin >> command;

        if(command == "CHANGE_CAPITAL")
        {
            std::cin >> country >> new_capital;

            //если не нашли -- заводим
            if(country_capital.find(country) == country_capital.end())
            {
                country_capital[country] = new_capital;
                std::cout << "Introduce new country " << country << " with capital " << new_capital << std::endl;
            }
            else if(country_capital[country] == new_capital)
            {
                std::cout << "Country " << country << " hasn't changed its capital" << std::endl;
            }
            else
            {
                std::cout << "Country " << country << " has changed its capital from " << country_capital[country] << " to " << new_capital << std::endl;
                country_capital[country] = new_capital;
            }

        }
        else if(command == "RENAME")
        {
            std::cin >> old_country_name >> new_country_name;

            //если страна есть в словаре и переименовывается на новое название
            if(old_country_name != new_country_name && country_capital.find(old_country_name) != country_capital.end() && country_capital.find(new_country_name) == country_capital.end())
            {
                std::cout << "Country " << old_country_name << " with capital " << country_capital[old_country_name] << " has been renamed to " << new_country_name << std::endl;

                country_capital[new_country_name] = country_capital[old_country_name];
                country_capital.erase(old_country_name);
            }
            else
            {
                std::cout << "Incorrect rename, skip" << std::endl;
            }
        }
        else if(command == "ABOUT")
        {
            std::cin >> country;

            if(country_capital.find(country) != country_capital.end())
            {
                std::cout << "Country " << country << " has capital " << country_capital[country] << std::endl;
            }
            else
            {
                std::cout << "Country " << country << " doesn't exist" << std::endl;
            }
        }
        else if(command == "DUMP")
        {
            if(country_capital.empty())
            {
                std::cout << "There are no countries in the world" << std::endl;
            }
            else
            {
                for(auto re : country_capital)
                    std::cout << re.first << "/" << re.second << " ";
                std::cout << std::endl;    
            }
            
        }
        
    }

    return 0;
    
}
