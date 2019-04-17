#include"bus_manager.h"

void BusManager::AddBus(const std::string& bus, const std::vector<std::string>& stops) {
  for(auto stop : stops){
    buses_to_stops[bus].push_back(stop);
    stops_to_buses[stop].push_back(bus);
  }
}

BusesForStopResponse BusManager::GetBusesForStop(const std::string& stop) const {
  BusesForStopResponse list_of_stops;
  list_of_stops.stop = stop;
  try {
    list_of_stops.stops_to_buses = stops_to_buses.at(stop);
  } catch (...) {
    list_of_stops.is_empty = true;
  }
  return list_of_stops;
}

StopsForBusResponse BusManager::GetStopsForBus(const std::string& bus) const {
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

AllBusesResponse BusManager::GetAllBuses() const {
  AllBusesResponse all_bus;
  all_bus.buses_to_stops = buses_to_stops;
  return all_bus;
}

