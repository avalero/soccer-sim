

#include "stringutils.h"
#include "types.h"
#include <MinimalSocket/udp/UdpSocket.h>
#include <vector>
#include "parseseemessages.h"
#include "parsehearmessages.h"

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

    for (string m : messages)
    {
      if (m.starts_with("see"))
      {
        std::cout << "SEE\n==================================================\n"
                  << message << std::endl;
        std::cout << m << std::endl;
        // extract time from messages
        player = parseMatchData(m, player);
        player = parseSeeMessage(m, player);
      }
      else if (m.starts_with("sense_body"))
      {
        // extract time from messages
        player = parseMatchData(m, player);
        // TODO
      }
      else if (m.starts_with("hear"))
      {
        cout << "Hear message: " << m << endl;
        // extract time from messages
        player = parseMatchData(m, player);

        player = parseHearMessage(m, player);
        cout << player << endl;
      }
      else if (m.starts_with("change_player_type") || m.starts_with("ok"))
      {
        // TODO
      }
      else if (m.starts_with("player_type"))
      {
        // TODO
      }
      else if (m.starts_with("player_param"))
      {
        // TODO
      }
      else
      {
        cout << "Message not recognized:\n=====================================\n " << m << endl;
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
