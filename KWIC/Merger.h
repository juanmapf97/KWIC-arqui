//
//  Merger.h
//  KWIC
//
//  Created by Juanma on 5/11/19.
//  Copyright © 2019 Juanma. All rights reserved.
//

#ifndef Merger_h
#define Merger_h

#include <vector>
#include <numeric>

class Merger {
    std::vector<std::string> merged;
    
public:
    Merger(std::vector<std::vector<std::string>> shifted);
    std::vector<std::string> getMergedSentences();
};

Merger::Merger(std::vector<std::vector<std::string>> shifted) {
    for (int i = 0; i < shifted.size(); i++) {
        std::string merg = "";
        for (int j = 0; j < shifted[i].size(); j++) {
            merg += shifted[i][j] + " ";
        }
        merg.erase(merg.end()-1);
        merged.push_back(merg);
    }
}

std::vector<std::string> Merger::getMergedSentences() {
    return merged;
}

#endif /* Merger_h */
