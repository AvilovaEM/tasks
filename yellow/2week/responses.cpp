#include<responses.h>

std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r) {
  if (r.is_empty) {
    os << "No stop";
  } else {
    for (const std::string& bus : r.stops_to_buses)
      os << bus << " ";
  }
  return os;
}

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


