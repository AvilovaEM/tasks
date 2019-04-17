#include<iostream>
#include<string>
#include<algorithm>

bool comp(const std::string& str1, const std::string& str2)
        {
            if(str1 < str2)
                return true;
            else
                return false;
        }

class SortedStrings
{
    public:
        void AddString(const std::string& str)
        {
            vect_string.push_back(str);
        }
        
        std::vector<std::string> GetSortedStrings()
        {
            std::sort(vect_string.begin(), vect_string.end(), comp);
            return vect_string;            
        }

    private:
        std::vector<std::string> vect_string;
}; 
/*
void PrintSortedStrings(SortedStrings& strings)
{
    for(const std::string& s: strings.GetSortedStrings())
    {
        std::cout << s << " ";
    }
    std::cout << std::endl;
}

int main()
{

    SortedStrings str;

    str.AddString("first");
    str.AddString("second");
    str.AddString("thrid");

    PrintSortedStrings(str);

    str.AddString("second");

    PrintSortedStrings(str);

    return 0;
}*/
