#include<iostream>
#include<map>
#include<exception>
#include<string>

//template<typename Key, typename Value> *Value GetRefStrict(const std::map<Key, Value>& map_arg, Key key_arg);
template<typename Key, typename Value> Value& GetRefStrict(std::map<Key, Value>& map_arg, Key key_arg){
  try{
    return map_arg.at(key_arg);
  } catch(...){
    throw std::runtime_error("");
  }
};
