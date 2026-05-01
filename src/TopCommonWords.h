#ifndef TOPCOMMONWORDS_TOPCOMMONWORDS_H
#define TOPCOMMONWORDS_TOPCOMMONWORDS_H

#include <istream>
#include <map>
#include <ostream>
#include <string>
#include <utility>
#include <vector>

std::string cleanWord(const std::string& s);
bool skipWord(const std::string& s);
std::map<std::string,int> countWords(std::istream& in);
std::vector<std::pair<int,std::vector<std::string>>> topWords(const std::map<std::string,int>& m,int n);
std::string showWords(const std::vector<std::string>& v);
void printTop(const std::vector<std::pair<int,std::vector<std::string>>>& v,std::ostream& out);

#endif
