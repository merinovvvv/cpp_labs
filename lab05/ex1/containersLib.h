#include <set>
#include <string>

#ifndef CONTAINERS_LIB_H_
#define CONTAINERS_LIB_H_

std::multiset<std::string> readMultiset(std::string filePath);
void printMultiset(std::string filePath, std::multiset<std::string> container);

#endif // CONTAINERS_LIB_H_
