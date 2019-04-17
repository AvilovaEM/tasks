#include<iostream>
#include<vector>
#include<algorithm>

bool IsNegative(int number){
  return number < 0;
}

void PrintVectorPart(const std::vector<int>& numbers){
  auto position = std::find_if(begin(numbers), end(numbers), IsNegative);

  while(position-- != begin(numbers))
    std::cout << *position << " ";
  std::cout << std::endl;
}
