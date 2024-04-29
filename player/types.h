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

struct MatchInit
{
  FIELD field;
  int number;
};

struct BallData
{
  double x;
  double y;
  double vx;
  double vy;
};

struct MatchData
{
  int time;
};

struct SeeData
{
  BallData ball;
};

struct Player
{
  MatchInit config;
  MatchData match;
  SeeData see;
};

ostream &operator<<(ostream &os, const MatchInit &response);

ostream &operator<<(ostream &os, const SeeData &see);
ostream &operator<<(ostream &os, const BallData &ball);
ostream &operator<<(ostream &os, const MatchData &match);

ostream &operator<<(ostream &os, const Player &player);

#endif // TYPES_H