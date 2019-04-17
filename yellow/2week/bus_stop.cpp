#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  std::string bus;
  std::string stop;
  std::vector<std::string> stops;
};

std::istream& operator >> (std::istream& is, Query& q) {
  std::string operation_code;
  is >> operation_code;

  if (operation_code == "NEW_BUS"){
    q.type = QueryType::NewBus;
    is >> q.bus;

    int stop_count;
    is >> stop_count;
    std::vector<std::string> from_stop_tmp;
    for (int i = 0; i < stop_count; ++i) {
      std::string stop;
      is >> stop;
      from_stop_tmp.push_back(stop);
    }
    q.stops = from_stop_tmp;
  } else if (operation_code == "BUSES_FOR_STOP"){
    q.type = QueryType::BusesForStop;
    is >> q.stop;
  } else if (operation_code == "STOPS_FOR_BUS"){
    q.type = QueryType::StopsForBus;
    is >> q.bus;
  } else if (operation_code == "ALL_BUSES")
    q.type = QueryType::AllBuses;

  return is;
}

struct BusesForStopResponse {
  std::string stop;
  bool is_empty = false;
  std::vector<std::string> stops_to_buses;
};

std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r) {
  if (r.is_empty) {
    os << "No stop";
  } else {
    for (const std::string& bus : r.stops_to_buses)
      os << bus << " ";
  }
  return os;
}

struct StopsForBusResponse {
  std::string bus;
  bool is_empty = false;
  std::vector<std::string> buses_to_stops;
  std::map<std::string, std::vector<std::string>> stops_for_buses;
};

std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r) {
  if (r.is_empty) {
    os << "No bus";
  } else {
    for (const std::string& stop : r.buses_to_stops) {
      os << "Stop " << stop << ": ";
      if (r.stops_for_buses.at(stop).size() == 1) {
        os << "no interchange";
      } else {
        for (const std::string& other_bus : r.stops_for_buses.at(stop)) {
          if (r.bus != other_bus) {
            os << other_bus << " ";
          }
        }
      }
      os << std::endl;
    }
  }

  return os;
}

struct AllBusesResponse {
  std::map<std::string, std::vector<std::string>> buses_to_stops;
};

std::ostream& operator << (std::ostream& os, const AllBusesResponse& r) {
  if (r.buses_to_stops.empty()) {
    os << "No buses";
  } else {
    for (const auto& bus_item : r.buses_to_stops) {
      os << "Bus " << bus_item.first << ": ";
      for (const std::string& stop : bus_item.second) {
        os << stop << " ";
      }
        os << std::endl;
    }
  }
  return os;
}

class BusManager {
public:
  void AddBus(const std::string& bus, const std::vector<std::string>& stops) {
    for(auto stop : stops){
      buses_to_stops[bus].push_back(stop);
      stops_to_buses[stop].push_back(bus);
    }
  }

  BusesForStopResponse GetBusesForStop(const std::string& stop) const {
    BusesForStopResponse list_of_stops;
    list_of_stops.stop = stop;
    try {
      list_of_stops.stops_to_buses = stops_to_buses.at(stop);
    } catch (...) {
      list_of_stops.is_empty = true;
    }
    return list_of_stops;
  }

  StopsForBusResponse GetStopsForBus(const std::string& bus) const {
    StopsForBusResponse list_of_buses;
    list_of_buses.bus = bus;
    try {
      list_of_buses.buses_to_stops = buses_to_stops.at(bus);
    } catch (...) {
      list_of_buses.is_empty = true;
    }

    list_of_buses.stops_for_buses = stops_to_buses;
    return list_of_buses;
  }

  AllBusesResponse GetAllBuses() const {
    AllBusesResponse all_bus;
    all_bus.buses_to_stops = buses_to_stops;
    return all_bus;
  }
private:
   std::map<std::string, std::vector<std::string>> buses_to_stops, stops_to_buses;
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
  int query_count;
  Query q;

  std::cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    std::cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      std::cout << bm.GetBusesForStop(q.stop) << std::endl;
      break;
    case QueryType::StopsForBus:
      std::cout << bm.GetStopsForBus(q.bus) << std::endl;
      break;
    case QueryType::AllBuses:
      std::cout << bm.GetAllBuses() << std::endl;
      break;
    }
  }

  return 0;
}
