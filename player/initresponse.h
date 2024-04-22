#ifndef INITRESPONSE_H
#define INITRESPONSE_H
#include "types.h"
#include <string>

using namespace std;

struct MatchInitResponse
{
  string field;
  int number;
};

MatchInitResponse parseInitResponse(string response)
{
  MatchInitResponse matchInitResponse;
  matchInitResponse.field = response.substr(1, response.find(")") - 1);
  matchInitResponse.number = stoi(response.substr(response.find("version") + 8, response.find(")")));
  return matchInitResponse;
}

#endif // INITRESPONSE_H