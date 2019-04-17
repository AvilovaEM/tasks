#include<iostream>
#include<string>
#include<algorithm>

class ReversibleString
{
    public:
        ReversibleString()
        {}
        ReversibleString(const std::string& str_start)
        {
            str_pr = str_start;
        }
        std::string ToString() const
        {
            return str_pr;
        }
        void Reverse()
        {
            std::reverse(str_pr.begin(), str_pr.end());
        }
    private:
        std::string str_pr;
    
};

int main() {
  ReversibleString s("live");
  s.Reverse();
  std::cout << s.ToString() << std::endl;
  
  s.Reverse();
  const ReversibleString& s_ref = s;
  std::string tmp = s_ref.ToString();
  std::cout << tmp << std::endl;
  
  ReversibleString empty;
  std::cout << '"' << empty.ToString() << '"' << std::endl;
  
  return 0;
}
