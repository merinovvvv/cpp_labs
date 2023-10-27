#include "subsequence.h"
#include <algorithm>
#include <iostream>

std::vector<std::pair<std::string, int>> yesOrNo(std::vector<std::pair<std::string, std::string>>& list)
{
    std::vector<std::pair<std::string, int>> StrIntVectorPair;
    int index;
    std::string str;
    for (size_t i = 0; i != list.size(); ++i) {
        if (list[i].first.find(list[i].second) != std::string::npos) {
            str = "YES";
            for (size_t j = 0; j != list[i].first.size(); ++j) {
                if (list[i].first[j] == list[i].second[0])
                {
                    index = j;
                    break;
                }
            }
        }
        else {
            str = "NO";
            index = -1;
        }
        StrIntVectorPair.push_back(std::make_pair(str, index));
    }
    return StrIntVectorPair;
}
