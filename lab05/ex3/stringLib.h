#ifndef STRING_LIB_H_
#define STRING_LIB_H_
#include <vector>
#include <string>
#include <map>

void deletePunctuationSign(std::string& str);
void deletePunctuationSign(std::vector<std::string>& list);
std::map <std::string, size_t> wordAmount(const std::vector <std::string>& list);

#endif //STRING_LIB_H_