#ifndef PARSEMESSAGES_H
#define PARSEMESSAGES_H

#include <string>
#include "types.h"

#include <MinimalSocket/udp/UdpSocket.h>

/**
 * Parse the initial message from the server
 * @param message initial message from the server
 * @return MatchInitResponse with the field and number
 * @example parseInitialMessage("(init l 1)") -> MatchInitResponse{LEFT, 1}
 */
MatchInitResponse parseInitialMessage(const std::string &message);

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
#endif // PARSEMESSAGES_H