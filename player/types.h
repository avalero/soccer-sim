#ifndef TYPES_H
#define TYPES_H

#include <string>
#include <ostream>

using namespace std;

enum FIELD
{
  LEFT,
  RIGHT
};

struct MatchInitResponse
{
  FIELD field;
  int number;
};

struct Player
{
  MatchInitResponse config;
};

ostream &operator<<(ostream &os, const MatchInitResponse &response);

ostream &operator<<(ostream &os, const Player &player);

#endif // TYPES_H