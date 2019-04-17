#include<iostream>
#include<string>
#include<map>
//#include<algorithm>

class Person
{
    public:
        void ChangeFirstName(int year, const std::string& first_name)
        {
            first_name_dict[year] = first_name;
        }
        
        void ChangeLastName(int year, const std::string& last_name)
        {
            last_name_dict[year] = last_name;
        }

        std::string GetFullName(int year)
        {
            std::string first_name_cout = "";
            std::string second_name_cout = "";
            std::map<int, std::string>::iterator fname_low;
            std::map<int, std::string>::iterator lname_low;

            fname_low = first_name_dict.lower_bound(year);
            lname_low = last_name_dict.lower_bound(year);

            std::cout << fname_low->second << std::endl;

/*
            auto fname_low = first_name_dict.lower_bound(year); 
            auto sname_low = last_name_dict.lower_bound(year);
            
            if(fname_low.first == year)
            {
                first_name_cout = first_name_dict[year];
            }
            else if(fname_low != first_name_dict.begin())
            {
                fname_low--;
                first_name_cout = fname_low.second;
            }
            
            if(sname_low.first == year)
            {
                second_name_cout = last_name_dict[year];
            }  
            else if(sname_low != last_name_dict.begin())
            {
                sname_low--;
                second_name_cout = sname_low.second;
            }           

            for(auto key_map : first_name_dict)
            {
                std::cout << "test: " << key_map.first << std::endl;
                if(year == key_map.first)
                {
                    first_name_cout = key_map.second;
                    break;
                } 
                else if(year < key_map.first)
                {
                    key_map.;
                    first_name_cout = key_map.second;
                    break;                    
                }
            }

            for(auto key_map : last_name_dict)
            {
                if(year == key_map.first)
                {
                    second_name_cout = key_map.second;
                    break;              
                }
                else if(year < key_map.first)
                {
                    key_map--;
                    second_name_cout = key_map.second;
                }
            }
  */          
            if(first_name_cout.size() == 0 && second_name_cout.size() == 0)
            {
                std::cout << "Incognito" << std::endl;
            }
            else if(first_name_cout.size() == 0)
            {
                std::cout << second_name_cout << " with unknown first name" << std::endl;
            }
            else if(second_name_cout.size() == 0)
            {
                std::cout << first_name_cout << " with unknown second name" << std::endl;
            }
            else
            {
                std::cout << first_name_cout << " " << second_name_cout << std::endl;
            }
        }
    private:
        std::map<int, std::string> first_name_dict;
        std::map<int, std::string> last_name_dict;        
    
};

int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    std::cout << person.GetFullName(year) << std::endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    std::cout << person.GetFullName(year) << std::endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    std::cout << person.GetFullName(year) << std::endl;
  }
  
  return 0;
}

