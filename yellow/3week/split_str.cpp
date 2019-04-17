#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<algorithm>

std::vector<std::string> SplitIntoWords(const std::string& s){
  auto begin_position = begin(s);
  auto end_position = begin(s);
  std::vector<std::string> res;

  while(begin_position != end(s)){
    end_position = std::find_if(begin_position, end(s), isspace);
    std::string tmp_word = "";
    for(auto it = begin_position; it < end_position; ++it)
      tmp_word += *it;

    res.push_back(tmp_word);
    if(end_position != end(s))
      begin_position = end_position + 1;
    else
      begin_position = end_position;
  }

  return res;
}

int main() {
  std::string s = "C Cpp Java Python";

  std::vector<std::string> words = SplitIntoWords(s);
  std::cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      std::cout << "/";
    }
    std::cout << *it;
  }
  std::cout << std::endl;

  return 0;
}

