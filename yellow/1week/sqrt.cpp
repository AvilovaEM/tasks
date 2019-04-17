#include<iostream>
#include<map>
#include<vector>
#include<utility>

using namespace std;

template<typename T> T Sqr(T x);
template<typename T> std::vector<T> Sqr(const std::vector<T>& arg);
template<typename Key, typename Value> std::map<Key, Value> Sqr(const std::map<Key, Value>& arg);
template<typename First, typename Second> std::pair<First, Second> operator*(const std::pair<First, Second>& lhs, const std::pair<First, Second>& rhs);
template<typename First, typename Second> std::pair<First, Second> Sqr(std::pair<First, Second> arg);


template <typename T> T Sqr(T x) {
  return x*x;
}

template<typename T> std::vector<T> Sqr(const std::vector<T>& arg){
  std::vector<T> result(arg.size());

  for(size_t i = 0; i < result.size(); ++i)
    result[i] = Sqr(arg[i]);

  return result;
}

template<typename Key, typename Value> std::map<Key, Value> Sqr(const std::map<Key, Value>& arg){
  std::map<Key, Value> result;

  for(auto key : arg)
    result[key.first] = Sqr(key.second);

  return result;
}

template<typename First, typename Second> std::pair<First, Second> operator*(const std::pair<First, Second>& lhs, const std::pair<First, Second>& rhs){
  First first_arg = lhs.first * rhs.first;
  Second second_arg = lhs.second * rhs.second;

  return {first_arg, second_arg};
}

template<typename First, typename Second> std::pair<First, Second> Sqr(std::pair<First, Second> arg){
  return {Sqr(arg.first), Sqr(arg.second)};
}

int main(){
  // Пример вызова функции
  std::vector<int> v = {1, 2, 3};
  std::cout << "vector:";
  for (int x : Sqr(v)) {
    std::cout << ' ' << x;
  }
  std::cout << std::endl;

  std::map<int, int> sqrt = {{1, 1}, {2, 4}, {3, 9}};
  for(auto key : Sqr(sqrt))
    std::cout << key.first << " - " << key.second << std::endl;

  std::map<int, std::pair<int, int>> map_of_pairs = {
    {4, {2, 2}},
    {7, {4, 3}}
  };
  std::cout << "map of pairs:" << std::endl;
  for (const auto& x : Sqr(map_of_pairs)) {
    std::cout << x.first << ' ' << x.second.first << ' ' << x.second.second << std::endl;
  }

  return 0;
}


'T Sqr(T) [with T = std::map<int, std::vector<double> >]':
\n/tmp/tmp3oua5va7.cpp:104:20:
   required from 'std::vector<T> Sqr(const std::vector<T>&) [with T = std::map<int, std::vector<double> >]'\n/tmp/tmp3oua5va7.cpp:163:27:   required from here\n/tmp/tmp3oua5va7.cpp:96:11: error: no match for 'operator*' (operand types are 'std::map<int, std::vector<double> >' and 'std::map<int, std::vector<double> >')\n   return x*x;\n          ~^~\n/tmp/tmp3oua5va7.cpp:120:68: note: candidate: template<class First, class Second> std::pair<_T1, _T2> operator*(const std::pair<_T1, _T2>&, const std::pair<_T1, _T2>&)\n template<typename First, typename Second> std::pair<First, Second> operator*(const std::pair<First, Second>& lhs, const std::pair<First, Second>& rhs){\n                                                                    ^~~~~~~~\n/tmp/tmp3oua5va7.cpp:120:68: note:   template argument deduction/substitution failed:\n/tmp/tmp3oua5va7.cpp:96:11: note:   'std::map<int, std::vector<double> >' is not derived from 'const std::pair<_T1, _T2>'\n   return x*x;\n          ~^~\n" (Time used: 0.00/1.00, preprocess time used: 0/None, memory used: 9355264/536870912.)
0/1Оценка: 0 из 1
НетЗадание не пройдено
0/1Оценка: 0 из 1
НетЗадание не пройдено
0/1Оценка: 0 из 1
НетЗадание не пройдено
0/1Оценка: 0 из 1
НетЗадание не пройдено
