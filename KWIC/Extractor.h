//
//  Extractor.h
//  KWIC
//
// Chilaquiles Pendientes
//

#ifndef Extractor_h
#define Extractor_h

#include <vector>
#include <iostream>

/*
 * Extractor. Receives a vector of strings, representing sentences delimited by spaces and
 * extract each individual word into a vector of vectors of strings.
 */
class Extractor {
    std::vector<std::vector<std::string>> sentenceWords;
    
public:
    Extractor(std::vector<std::string> sentences);
    std::vector<std::vector<std::string>> getExtractedWords();
};

/*
 * Extractor. Extracts a list of tokens (words) from a string denoting a sentence.
 * @params sentences. A vector of strings denoting sentences (space separated words).
 */
Extractor::Extractor(std::vector<std::string> sentences) {
    for (int i = 0; i < sentences.size(); i++) {
        std::vector<std::string> tokens;
        size_t pos = 0;
        std::string delimiter = " ";
        
        // While the word hasn't finish, get next space position and extract word
        while ((pos = sentences[i].find(delimiter)) != std::string::npos) {
            std::string token = sentences[i].substr(0, pos);
            tokens.push_back(token);
            sentences[i].erase(0, pos + delimiter.length());
        }
        tokens.push_back(sentences[i]);
        sentenceWords.push_back(tokens);
    }
}

/*
 * Getter for the sentenceWords attribute.
 * @return A vector of vector of strings denoting each word in a sentence.
 */
std::vector<std::vector<std::string>> Extractor::getExtractedWords() {
    return sentenceWords;
}

#endif /* Extractor_h */
