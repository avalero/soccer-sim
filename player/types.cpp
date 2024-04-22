#include "types.h"
#include <ostream>

using namespace std;

ostream &operator<<(ostream &os, const MatchInitResponse &response)
{
  os << "\nMatchInitResponse:\n-------------------\n";
  os << "Field:\t" << (response.field == FIELD::LEFT ? "LEFT" : "RIGHT");
  os << "\nNumber:\t" << response.number << "\n-------------------\n";
  return os;
}

ostream &operator<<(ostream &os, const Player &player)
{
  os << "Player: " << player.config;
  return os;
}