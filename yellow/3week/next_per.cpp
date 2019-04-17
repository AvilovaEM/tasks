#include<iostream>
#include<algorithm>
#include<vector>

int main(){
  int num;
  std::cin >> num;

  std::vector<int> all_num;

  for(int i = num; i >= 1; --i)
    all_num.push_back(i);

  do {
    for(auto item : all_num)
      std::cout << item << ' ';
    std::cout << std::endl;
    } while (std::prev_permutation(begin(all_num), end(all_num)));

  return 0;
}
