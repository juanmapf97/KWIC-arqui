//
//  Permuter.h
//  KWIC
//
// Chilaquiles Pendientes
//

#ifndef Permuter_h
#define Permuter_h

#include <iostream>
#include <vector>

/*
* Rotator. Generates all possible rotations from a vector of vector of sentence tokens.
*/
class Rotator {
    std::vector<std::vector<std::string>> rotated;
    
public:
    Rotator(std::vector<std::vector<std::string>> extracted);
    std::vector<std::vector<std::string>> getRotatedSentences();
};

/*
 * Rotator. Generates the rotated list of tokens by moving a pivot through the word denoting which tokens shall move around.
 * @params extracted. The vector of vector of extracted tokens to be rotated, may be of any size.
 */
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

/*
 * Getter for the extracted attribute
 * @return rotated. A vector with all possible rotations as a list of tokens
 */
std::vector<std::vector<std::string>> Rotator::getRotatedSentences() {
    return rotated;
}

#endif /* Permuter_h */
