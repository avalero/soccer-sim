#ifndef PARSEMESSAGES_H
#define PARSEMESSAGES_H

#include <string>
#include "types.h"

/**
 * Parse the initial message from the server
 * @param message initial message from the server
 * @return MatchInitResponse with the field and number
 * @example parseInitialMessage("(init l 1)") -> MatchInitResponse{LEFT, 1}
 */
MatchInitResponse parseInitialMessage(const std::string &message);

#endif // PARSEMESSAGES_H