

#include "stringutils.h"
#include "types.h"
#include "parsemessages.h"
#include <MinimalSocket/udp/UdpSocket.h>
#include <vector>

using namespace std;

MatchInitResponse parseInitialMessage(const std::string &message)
{
  auto initial_message = splitInParenthesesGroups(message);
  auto initial_message_content = splitInWords(initial_message[0]);
  if (initial_message_content[0] != "init")
  {
    throw std::runtime_error("Invalid initial message");
  }
  auto field = initial_message_content[1] == "l" ? FIELD::LEFT : FIELD::RIGHT;
  auto number = std::stoi(initial_message_content[2]);
  return MatchInitResponse{field, number};
}

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
