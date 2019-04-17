#include<iostream>
#include<algorithm>
#include<iterator>
#include<vector>

using namespace std;
/*
template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
  if(range_end - range_begin < 2)
    return;

  std::vector<typename RandomIt::value_type> elements(range_begin, range_end);
  auto half_it = elements.begin() + (elements.end() - elements.begin()) / 2;
  MergeSort(elements.begin(), half_it);
  MergeSort(half_it, elements.end());

  std::merge(elements.begin(), half_it, half_it, elements.end(), range_begin);
}
*/

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
  if(range_end - range_begin < 2)
    return;

  std::vector<typename RandomIt::value_type> elements(range_begin, range_end);
  auto first_thrid_it = elements.begin() + (elements.end() - elements.begin()) / 3;
  auto second_thrid_it = elements.begin() + 2 * (elements.end() - elements.begin()) / 3;
  MergeSort(elements.begin(), first_thrid_it);
  MergeSort(first_thrid_it, second_thrid_it);
  MergeSort(second_thrid_it, elements.end());

  std::vector<typename RandomIt::value_type> tmp;

  std::merge(elements.begin(), first_thrid_it, first_thrid_it, second_thrid_it, std::back_inserter(tmp));
  std::merge(tmp.begin(), tmp.end(), second_thrid_it, elements.end(), range_begin);
}

int main() {
  std::vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
  return 0;
}



