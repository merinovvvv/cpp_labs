#pragma once
#include <set>
#include <string>
#include <algorithm>
#include <iostream>

#ifndef MULTISET_OPERATIONS_H_
#define MULTISET_OPERATIONS_H_

std::multiset<std::string> unification(std::multiset<std::string> container1, std::multiset<std::string> container2);
std::multiset<std::string> intersection(std::multiset<std::string> container1, std::multiset<std::string> container2);
std::multiset<std::string> multisetsDifference(std::multiset<std::string> container1, std::multiset<std::string> container2);


#endif // MULTISET_OPERATIONS_H_