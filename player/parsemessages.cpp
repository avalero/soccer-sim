

#include "stringutils.h"
#include "types.h"
#include <MinimalSocket/udp/UdpSocket.h>
#include <vector>
#include "parseseemessages.h"

using namespace std;

namespace Parser
{

  /** (message time ...)
   * example: (see 328 ...)
   *
   */
  Player &parseMatchData(const std::string &message, Player &player)
  {
    auto match_data_content = splitInWords(message);
    //[ "(message", "328", ... ];
    try
    {
      player.match.time = std::stoi(match_data_content[1]);
    }
    catch (const std::exception &e)
    {
      cout << "Error parsing time: " << e.what() << endl;
    }
    return player;
  }

  Player &parseInitialMessage(const std::string &message, Player &player)
  {
    auto initial_message = splitInParenthesesGroups(message);
    auto initial_message_content = splitInWords(initial_message[0]);
    //[ "init", "l", "1" ];
    if (initial_message_content[0] != "init")
    {
      throw std::runtime_error("Invalid initial message");
    }
    auto field = initial_message_content[1] == "l" ? FIELD::LEFT : FIELD::RIGHT;
    auto number = std::stoi(initial_message_content[2]);
    player.config = MatchInit{field, number};
    return player;
  }

  Player &parseSeverMessage(const std::string &message, Player &player)
  {
    auto messages = splitInParenthesesGroups(message);

    for (string message : messages)
    {

      if (message.starts_with("see"))
      {
        // extract time from messages
        player = parseMatchData(message, player);
        player = parseSeeMessage(message, player);
      }
      else if (message.starts_with("sense_body"))
      {
        // extract time from messages
        player = parseMatchData(message, player);
        // TODO
      }
      else if (message.starts_with("hear"))
      {
        // extract time from messages
        player = parseMatchData(message, player);
        // TODO
      }
      else if (message.starts_with("change_player_type") || message.starts_with("ok"))
      {
        // TODO
      }
      else if (message.starts_with("player_type"))
      {
        // TODO
      }
      else if (message.starts_with("player_param"))
      {
        // TODO
      }
      else
      {
        cout << "Message not recognized: " << message << endl;
      }
    }
    return player;
  }

} // namespace Player

void sendInitialMoveMessage(const Player &player,
                            MinimalSocket::udp::Udp<true> &udp_socket,
                            MinimalSocket::Address const &recipient)
{
  struct Posicion
  {
    int x;
    int y;
  };

  vector<Posicion>
      posiciones = {{50, 0},
                    {35, -20},
                    {35, 20},
                    {20, -25},
                    {18, -9},
                    {18, 5},
                    {20, 20},
                    {2, -18},
                    {28, -18},
                    {35, 11},
                    {5, 0}};
  Posicion myPos = posiciones[player.config.number - 1];

  auto moveCommand = "(move " + to_string(myPos.x) + " " + to_string(myPos.y) + ")";
  udp_socket.sendTo(moveCommand, recipient);
}
