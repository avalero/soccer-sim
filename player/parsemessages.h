#ifndef PARSEMESSAGES_H
#define PARSEMESSAGES_H

#include <string>
#include "types.h"

#include <MinimalSocket/udp/UdpSocket.h>

namespace Parser
{

  /**
   * Player the match data from the server, for example the time
   * @param message match data from the server
   * @return MatchData
   * @example PlayerMatchData("(see 0)") -> MatchData{0}
   */
  Player &parseMatchData(const std::string &message, Player &player);

  /**
   * Player the initial message from the server
   * @param message initial message from the server
   * @return MatchInitResponse with the field and number
   * @example PlayerInitialMessage("(init l 1)") -> MatchInitResponse{LEFT, 1}
   */
  Player &parseInitialMessage(const std::string &message, Player &player);

  /**
   * Player the server message
   * @param message server message
   * @return Player
   */
  Player &parseSeverMessage(const std::string &message, Player &player);

} // namespace Parser

/**
 * Send the initial move message to the server
 * @param player player configuration
 * @param udp_socket udp socket to send the message
 * @param recipient server address
 * @example sendInitialMessage(Player{MatchInitResponse{LEFT, 1}}, udp_socket, MinimalSocket::Address{"
 *
 */
void sendInitialMoveMessage(const Player &player,
                            MinimalSocket::udp::Udp<true> &udp_socket,
                            MinimalSocket::Address const &recipient);
#endif // PlayerMESSAGES_H