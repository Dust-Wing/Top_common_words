#ifndef TOPCOMMONWORDS_TOPCOMMONWORDS_H
#define TOPCOMMONWORDS_TOPCOMMONWORDS_H

#include <istream>
#include <map>
#include <ostream>
#include <string>
#include <vector>

std::string cleanWord(const std::string& s);
bool skipWord(const std::string& s);
std::string showWords(const std::vector<std::string>& v);

#endif
