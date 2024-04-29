#include "types.h"
#include "parseseemessages.h"
#include "stringutils.h"

namespace Parser
{
  Player &parseSeeMessage(const std::string &message, Player &player)
  {
    // check if the string starts with "see"
    if (!message.starts_with("see"))
    {
      throw std::runtime_error("Invalid see message");
    }

    auto see_message = splitInParenthesesGroups(message);

    //  [ "see 0", "((b) 0 0 0 0)" ]
    for (string message : see_message)
    {
      if (message.find("(b)") != std::string::npos)
      {
        player.see = SeeData{See::parseBallData(message, player.see)};
      }
    }
    return player;
  }

  namespace See
  {
    SeeData &parseBallData(const std::string &message, SeeData &see)
    {
      // check if it is ball message
      if (message.find("(b)") == std::string::npos)
      {
        throw std::runtime_error("Invalid ball message");
      }

      auto ball_message = splitInWords(message);
      // [ "((b)", "0", "0", "0", "0))" ]
      auto distance = std::stod(ball_message[1]);
      auto direction = std::stod(ball_message[2]);
      auto distance_change = ball_message.size() > 3 ? std::stod(ball_message[3]) : 0;
      auto direction_change = ball_message.size() > 4 ? std::stod(ball_message[4]) : 0;
      see.ball = BallData{distance, direction, distance_change, direction_change};
      return see;
    }

  } // namespace See
} // namespace Parse