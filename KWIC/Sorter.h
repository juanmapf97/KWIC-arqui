//
//  Sorter.h
//  KWIC
//
//  Created by Juanma on 5/11/19.
//  Copyright © 2019 Juanma. All rights reserved.
//

#ifndef Sorter_h
#define Sorter_h

#include <vector>
#include <string>
#include <algorithm>

class Sorter {
    std::vector<std::string> sorted;
    
public:
    Sorter(std::vector<std::string> unsorted);
    std::vector<std::string> getSorted();
};

Sorter::Sorter(std::vector<std::string> unsorted) {
    std::sort(unsorted.begin(), unsorted.end(), [](const std::string& a, const std::string& b) -> bool {
        for (size_t c = 0; c < a.size() and c < b.size(); c++) {
            if (std::tolower(a[c]) != std::tolower(b[c]))
                return (std::tolower(a[c]) < std::tolower(b[c]));
        }
        return a.size() < b.size();
    });
    sorted = unsorted;
}

std::vector<std::string> Sorter::getSorted() {
    return sorted;
}

#endif /* Sorter_h */
