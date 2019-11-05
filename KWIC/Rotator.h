//
//  Permuter.h
//  KWIC
//
//  Created by Juanma on 5/11/19.
//  Copyright © 2019 Juanma. All rights reserved.
//

#ifndef Permuter_h
#define Permuter_h

#include <iostream>
#include <vector>

class Rotator {
    std::vector<std::vector<std::string>> rotated;
    
public:
    Rotator(std::vector<std::vector<std::string>> extracted);
    std::vector<std::vector<std::string>> getRotatedSentences();
};

Rotator::Rotator(std::vector<std::vector<std::string>> extracted) {
    for (int i = 0; i < extracted.size(); i++) {
        std::vector<std::string> temp(extracted[i].size());
        for (int j = 0; j < extracted[i].size(); j++) {
            int w = j;
            int k = 0;
            
            while (w < extracted[i].size()) {
                temp[k] = extracted[i][w];
                k++;
                w++;
            }
            
            w = 0;
            while (w < j) {
                temp[k] = extracted[i][w];
                w++;
                k++;
            }
            
            rotated.push_back(temp);
        }
    }
}

std::vector<std::vector<std::string>> Rotator::getRotatedSentences() {
    return rotated;
}

#endif /* Permuter_h */
