#include "./stringutils.h"

vector<string> splitInWords(string const &str, char delimiter)
{
  vector<string> words;
  string word = "";
  for (auto x : str)
  {
    if (x == delimiter)
    {
      words.push_back(word);
      word = "";
    }
    else
    {
      word = word + x;
    }
  }
  words.push_back(word);
  return words;
}

vector<string> splitInParenthesesGroups(string const &str)
{
  vector<string> groups;
  string group = "";
  int count = 0;
  for (auto x : str)
  {
    if (x == '(')
    {
      count++;
      continue;
    }
    if (x == ')')
    {
      count--;

      if (count == 0 && group != "")
      {
        groups.push_back(group);
        group = "";
      }
      continue;
    }

    if (count > 0)
    {
      group = group + x;
    }
  }
  return groups;
}

ostream &operator<<(ostream &os, const vector<string> &arr)
{
  os << "[ ";
  for (auto x : arr)
  {
    os << x << ", ";
  }
  os << "]";
  return os;
}