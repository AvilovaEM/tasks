#include<iostream>
#include<map>
#include<string>
#include<regex>
#include<exception>
#include<set>
#include<iomanip>

class Date {
public:
  Date(const std::string& string_data){
      static std::regex date_format("(-?\\d+)-(-?\\d+)-(-?\\d+)");
      static std::smatch matches;

      if(!std::regex_match(string_data, matches, date_format))
        throw std::invalid_argument("Wrong date format: " + string_data);

      year = stoi(matches[1]);
      month = stoi(matches[2]);
      day = stoi(matches[3]);

      if(12 < month || month < 1)
        throw std::invalid_argument("Month value is invalid: " + std::to_string(month));

      if(31 < day || day < 1)
        throw std::invalid_argument("Day value is invalid: " + std::to_string(day));
  }

  inline int GetYear() const{
      return year;
  }

  inline int GetMonth() const{
      return month;
  }

  inline int GetDay() const{
      return day;
  }

private:
  int year;
  int month;
  int day;
};

std::ostream& operator<<(std::ostream& stream, const Date& date){
  stream << std::setfill('0');
  stream << std::setw(4) << date.GetYear() << "-" << std::setw(2) << date.GetMonth() << "-" << std::setw(2) << date.GetDay();
  return stream;
}

bool operator<(const Date& lhs, const Date& rhs){
  if(lhs.GetYear() < rhs.GetYear())
    return true;
  if(lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() < rhs.GetMonth())
    return true;
  if(lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() < rhs.GetDay())
    return true;

  return false;
};

class Database {
public:
  void AddEvent(const Date& date, const std::string& event){
    data_base[date].insert(event);
  }

  bool DeleteEvent(const Date& date, const std::string& event){
    return data_base[date].erase(event);
  }

  int DeleteDate(const Date& date){
    int cnt = data_base[date].size();
    data_base.erase(date);
    return cnt;
  }

  void Find(const Date& date) const{
    for(const auto& event : data_base.at(date))
      std::cout << event << "\n";
  }

  void Print() const{
    for(const auto &item : data_base){
      for(const auto &event : item.second)
        std::cout << item.first << " " << event << "\n";
    }
  }
private:
  std::map<Date, std::set<std::string>> data_base;
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Database db;
  std::string command;
  std::vector<std::string> parse_command;
  while (getline(std::cin, command)) {
    if(command == "")
      continue;

    std::regex command_format("\\S+");
    parse_command.assign(
          std::sregex_token_iterator(command.begin(), command.end(), command_format),
          std::sregex_token_iterator()
    );

/*    while(command.find(" ") != std::string::npos){
      parse_command.push_back(command.substr(0, command.find(" ")));
      command.erase(0, command.find(" ")+1);
    }

    parse_command.push_back(command);
*/

    if(parse_command[0] == "Add"){
      try {
        Date date(parse_command[1]);
        db.AddEvent(date, parse_command[2]);
      } catch (const std::invalid_argument& exc) {
        std::cout << exc.what() << "\n";
        return 0;
      }
    } else if(parse_command[0] == "Del"){
      try {
        Date date(parse_command[1]);
        if(parse_command.size() == 2){
          std::cout << "Deleted " << db.DeleteDate(date) << " events\n";
        } else {
          if(db.DeleteEvent(date, parse_command[2]))
            std::cout << "Deleted successfully\n";
          else
            std::cout << "Event not found\n";
        }
      } catch (const std::invalid_argument& exc) {
        std::cout << exc.what() << "\n";
        return 0;
      }
    } else if(parse_command[0] == "Find"){
      try {
        Date date(parse_command[1]);
        db.Find(date);
      } catch (const std::invalid_argument& exc) {
        std::cout << exc.what() << "\n";
        return 0;
      } catch(const std::out_of_range&){

      }
    } else if(parse_command[0] == "Print"){
      db.Print();
    } else {
      std::cout << "Unknown command: " << parse_command[0] << "\n";
      return 0;
    }
  }
  return 0;
}
