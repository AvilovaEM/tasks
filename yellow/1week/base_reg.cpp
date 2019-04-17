#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<tuple>
#include<algorithm>
/*
enum class Lang {
  DE, FR, IT
};

struct Region {
  std::string std_name;
  std::string parent_std_name;
  std::map<Lang, std::string> names;
  int64_t population;
};
*/
bool operator==(const Region& lhs, const Region& rhs){
  auto lhs_key = tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population);
  auto rhs_key = tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
  return lhs_key == rhs_key;
}

bool operator<(const Region& lhs, const Region& rhs){
  auto lhs_key = tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population);
  auto rhs_key = tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
  return lhs_key < rhs_key;
}

int FindMaxRepetitionCount(const std::vector<Region>& regions){
  if(regions.empty())
    return 0;

  int max_count = 1;
  std::map<Region, int> count_map;

  for(auto item : regions){
    count_map[item]++;
    if(count_map[item] > max_count)
      max_count = count_map[item];
  }

  return max_count;
};
/*
int main() {
  Region t1 = {"Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89};
  Region t2 = {"Russia",
            "Eurasia",
            {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
            89};

  std::vector<Region> test{};
  std::cout << FindMaxRepetitionCount(test) << std::endl;

return 0;
}
*/
