#include<iostream>

int main(){
  uint64_t n;
  uint64_t rho;

  std::cin >> n >> rho;

  uint64_t weight = 0;

  for(uint64_t i = 0; i < n; ++i){
    uint64_t w, h, d;
    std::cin >> w >> h >> d;
    weight += rho * w * h * d;
  }

  std::cout << weight << std::endl;
  return 0;
}
