#include "query.h"

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
