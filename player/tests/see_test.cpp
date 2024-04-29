#include "../parseseemessages.h"
#include <gtest/gtest.h>
#include <iostream>
#include "../types.h"

TEST(parseSeeMessage, parseBall)
{
  string s = "see 0 ((f c) 38.1 -57) ((f c b) 20.7 5 0 0) ((f r t) 98.5 -42) ((f r b) 73 2) ((f g r b) 77.5 -19) ((g r) 79.8 -24) ((f g r t) 83.1 -28) ((f p r b) 58 -12) ((f p r c) 65.4 -30) ((f p r t) 76.7 -43) ((f t r 30) 87.4 -55) ((f t r 40) 93.7 -50) ((f t r 50) 100.5 -45) ((f b 0) 21.8 19 0 0) ((f b r 10) 31.5 13 0 0) ((f b r 20) 41.3 10) ((f b r 30) 50.9 8) ((f b r 40) 60.9 7) ((f b r 50) 70.8 6) ((f b l 10) 12.7 33 0 0) ((f r 0) 84.8 -22) ((f r t 10) 89.1 -28) ((f r t 20) 93.7 -34) ((f r t 30) 99.5 -38) ((f r b 10) 81.5 -16) ((f r b 20) 79 -9) ((f r b 30) 78.3 -1) ((b) 36.6 -57) ((l r) 73 90)";
  Player player;

  player = Parser::parseSeeMessage(s, player);
  EXPECT_EQ(player.see.ball.distance, 36.6);
  EXPECT_EQ(player.see.ball.direction, -57);
  EXPECT_EQ(player.see.ball.distance_change, 0);
  EXPECT_EQ(player.see.ball.direction_change, 0);
}