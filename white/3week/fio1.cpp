#include<map>
#include<iostream>
#include<string>

class Person
{
    public:
        void ChangeFirstName(int year, const std::string& f_name)
        {
            first_name[year] = f_name;
        }
        
        void ChangeLastName(int year, const std::string& l_name)
        {
            last_name[year] = l_name;
        }

        std::string GetFullName(int year)
        {
            auto f_name = first_name.begin();
            auto l_name = last_name.begin();
            /*
                нам надо проверить на нижнюю границу, далее все будет норм работать, кроме того, что нужно брать предыдущий
            */
            if((first_name.empty() && last_name.empty()) || (f_name->first > year && l_name->first > year))
            {
                return "Incognito";
            } else if(first_name.empty() || f_name->first > year)
            {
                std::string result = (--last_name.upper_bound(year))->second + " with unknown first name";
                return result;  
            } else if(last_name.empty() || l_name->first > year)
            {
                std::string result = (--first_name.upper_bound(year))->second + " with unknown last name";
                return result;  
            } else
            {
                std::string result = (--first_name.upper_bound(year))->second + " " + (--last_name.upper_bound(year))->second;
                return result;  

            }
            
        }
    private:
        std::map<int, std::string> first_name;
        std::map<int, std::string> last_name;
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
  
  person.ChangeLastName(1960, "Pupsikova");
  for (int year : {1900, 1965, 1990}) {
    std::cout << person.GetFullName(year) << std::endl;
  }
  
  return 0;
}

