

#include "stringutils.h"
#include "types.h"
#include "parsemessages.h"

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