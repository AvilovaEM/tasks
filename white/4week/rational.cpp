#include<iostream>
#include<sstream>
#include<map>
#include<set>
#include<vector>
#include<exception>
#include<stdexcept>

int GreatestCommonDivision(int a, int b) {
  int r = 0;

  while(a%b != 0){
    r = a%b;
    a = b;
    b = r;
  }
  
  if(r == 0)
    return b;
  else
    return r;
};

int positive_number(int number){
  if(number < 0)
    return -number;
  else
    return number;
};

int sign(int number) {
  return number < 0 ? -1 : 1;
}

class Rational{
public:
  Rational(){
    numerator = 0;
    denominator = 1;
  };
  
  Rational(int numerator_value, int denominator_value){
    if(denominator_value == 0)
      throw std::invalid_argument("div by zero");

    int sgn = sign(numerator_value) * sign(denominator_value);
    
    numerator_value = positive_number(numerator_value);
    denominator_value = positive_number(denominator_value);
    
    int gcd = GreatestCommonDivision(numerator_value, denominator_value);
    
    numerator = sgn * numerator_value / gcd;
    denominator = denominator_value / gcd;
  };
  
  int Numerator() const {
    return numerator;
  };
  
  int Denominator() const {
    return denominator;
  };
private:
  int numerator;
  int denominator;
};

Rational NegativeNumber(const Rational& number){
  Rational result(-number.Numerator(), number.Denominator());
  return result;
};

Rational ReverceNumber(const Rational& number){
  if(number.Numerator() == 0)
    throw std::domain_error("div by zero-number");

  Rational result(number.Denominator(), number.Numerator());
  return result;
};

bool operator==(const Rational& lhs, const Rational& rhs){
  if(lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator())
    return true;
  else
    return false;
};

Rational operator+(const Rational& lhs, const Rational& rhs){
  int res_numerator = lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator();
  int res_denominator = lhs.Denominator() * rhs.Denominator();
  
  Rational res(res_numerator, res_denominator);
  return res;
};

Rational operator-(const Rational& lhs, const Rational& rhs){
  Rational negative_rhs = NegativeNumber(rhs);
  return lhs + negative_rhs;
};

bool operator<(const Rational& lhs, const Rational& rhs){
  Rational difference;
  difference = lhs - rhs;
  if(difference.Numerator() < 0)
    return true;
  else
    return false;
}

Rational operator*(const Rational& lhs, const Rational& rhs){
  int res_numerator = lhs.Numerator() * rhs.Numerator();
  int res_denominator = lhs.Denominator() * rhs.Denominator();
  
  Rational result(res_numerator, res_denominator);
  return result;
}

Rational operator/(const Rational& lhs, const Rational& rhs){
  Rational reverce_rhs = ReverceNumber(rhs);
  return lhs * reverce_rhs;
};

std::ostream& operator<<(std::ostream& stream, const Rational& number){
  stream << number.Numerator() << "/" << number.Denominator();
  return stream;
};

std::istream& operator>>(std::istream& stream, Rational& number){
  int record_numerator = number.Numerator();
  int record_denominator = number.Denominator();
  
  stream >> record_numerator;
  stream.ignore(1);
  stream >> record_denominator;
  
  number = {record_numerator, record_denominator};
  return stream;
};

int main() {
    try {
        Rational r(1, 0);
        std::cout << "Doesn't throw in case of zero denominator" << std::endl;
        return 1;
    } catch (std::invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        std::cout << "Doesn't throw in case of division by zero" << std::endl;
        return 2;
    } catch (std::domain_error&) {
    }

    std::cout << "OK" << std::endl;
    return 0;
}
