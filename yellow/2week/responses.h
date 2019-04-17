#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<map>

struct BusesForStopResponse {
  std::string stop;
  bool is_empty = false;
  std::vector<std::string> stops_to_buses;
};

struct StopsForBusResponse {
  std::string bus;
  bool is_empty = false;
  std::vector<std::string> buses_to_stops;
  std::map<std::string, std::vector<std::string>> stops_for_buses;
};

struct AllBusesResponse {
  std::map<std::string, std::vector<std::string>> buses_to_stops;
};

std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r);
std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r);
std::ostream& operator << (std::ostream& os, const AllBusesResponse& r);


