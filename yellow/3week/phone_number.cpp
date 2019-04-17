#include<exception>
#include<string>
#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
#include"phone_number.h"
/*
class PhoneNumber {
public:
  explicit PhoneNumber(const std::string &international_number);

  std::string GetCountryCode() const;
  std::string GetCityCode() const;
  std::string GetLocalNumber() const;
  std::string GetInternationalNumber() const;

private:
  std::string country_code_;
  std::string city_code_;
  std::string local_number_;
};
*/
PhoneNumber::PhoneNumber(const std::string &international_number){
  if(international_number[0] != '+')
    throw std::invalid_argument("");

  char r = '-';
  auto country_code_pos = international_number.find(r);
  if(country_code_pos == std::string::npos || country_code_pos - 1 == 0)
    throw std::invalid_argument("");
  country_code_ = international_number.substr(1, country_code_pos - 1);

  auto city_code_pos = international_number.find(r, country_code_pos + 1);
  if(city_code_pos == std::string::npos || city_code_pos - country_code_pos == 0)
    throw std::invalid_argument("");
  city_code_ = international_number.substr(country_code_pos + 1, city_code_pos - country_code_pos - 1);

  local_number_ = international_number.substr(city_code_pos + 1);
  if(local_number_ == "")
    throw std::invalid_argument("");
};

std::string PhoneNumber::GetCountryCode() const{
  return country_code_;
};
std::string PhoneNumber::GetCityCode() const{
  return city_code_;
};
std::string PhoneNumber::GetLocalNumber() const{
  return local_number_;
};
std::string PhoneNumber::GetInternationalNumber() const{
  std::string number = "+";
  number += country_code_;
  number += "-";
  number += city_code_;
  number += "-";
  number += local_number_;

  return number;
};

/*
int main(){
  std::vector<std::string> test = {"+--", "+7-495-111-22-33", "+7-495-1112233", "+323-22-460002", "+1-2-coursera-cpp", "1-2-333", "+7-1233"};
  for(auto tmp : test){
    PhoneNumber a(tmp);
    std::cout << a.GetCountryCode() << " " << a.GetCityCode() << " " << a.GetLocalNumber() << std::endl;
    std::cout << a.GetInternationalNumber() << std::endl;
  }
  return 0;
}
*/
