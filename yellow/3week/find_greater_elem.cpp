#include<iostream>
#include<vector>
#include<set>
#include<string>

template <typename T>
std::vector<T> FindGreaterElements(const std::set<T>& elements, const T& border){
  std::vector<T> res;

  for(auto item : elements)
    if(item > border)
      res.push_back(item);

  return res;
}

int main() {
  for (int x : FindGreaterElements(std::set<int>{1, 5, 7, 8}, 5)) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  std::string to_find = "Python";
  std::cout << FindGreaterElements(std::set<std::string>{"C", "C++"}, to_find).size() << std::endl;
  return 0;
}
