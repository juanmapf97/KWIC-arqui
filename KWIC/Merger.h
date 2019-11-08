//
//  Merger.h
//  KWIC
//
// Chilaquiles Pendientes
//

#ifndef Merger_h
#define Merger_h

#include <vector>
#include <numeric>

/*
 * Merger. From a vector of vectors of tokens, generate the sentences as a single string.
 */
class Merger {
    std::vector<std::string> merged;
    
public:
    Merger(std::vector<std::vector<std::string>> shifted);
    std::vector<std::string> getMergedSentences();
};

/*
 * Merger. Generates a vector of strings from the list of tokens of each sentence by
 * concatenating them with a space.
 * @params shifted. The rotated vectors of tokens.
 */
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

/*
 * Getter for the merged attribute.
 * @return The vector of merged strings.
 */
std::vector<std::string> Merger::getMergedSentences() {
    return merged;
}

#endif /* Merger_h */
