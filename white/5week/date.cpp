#include<iostream>
#include<string>
#include<vector>
#include<regex>
#include<exception>

int main(){
  std::string command;

  getline(std::cin, command);

  int pos_space = command.find(" ");
  std::string what_command = command.substr(0, pos_space+1);

  //if(command == "")
  //  continue;

  if(what_command != "Add" || what_command != "Del" || what_command != "Find" || what_command != "Print")
    std::cout << "not command" << std::endl;
  if(what_command == "Add")

  return 0;
}
