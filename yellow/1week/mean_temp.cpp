#include<iostream>
#include<vector>
#include<cstdint>

int main(){
  size_t N;
  std::cin >> N;

  std::vector<int64_t> temperature(N);
  std::vector<size_t> day_num;
  int64_t sum = 0;

  for(auto& val : temperature){
    std::cin >> val;
    sum += val;
  }

  int64_t mean = sum / static_cast<int64_t>(temperature.size());

  for(size_t i = 0; i < N; ++i)
    if(temperature[i] > mean)
      day_num.push_back(i);

  std::cout << day_num.size() << std::endl;

  for(auto val : day_num)
    std::cout << val << " ";

  std::cout << std::endl;
  return 0;
}
