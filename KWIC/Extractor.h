//
//  Extractor.h
//  KWIC
//
//  Created by Juanma on 5/11/19.
//  Copyright © 2019 Juanma. All rights reserved.
//

#ifndef Extractor_h
#define Extractor_h

#include <vector>
#include <iostream>

class Extractor {
    std::vector<std::vector<std::string>> sentenceWords;
    
public:
    Extractor(std::vector<std::string> sentences);
    std::vector<std::vector<std::string>> getExtractedWords();
};

Extractor::Extractor(std::vector<std::string> sentences) {
    for (int i = 0; i < sentences.size(); i++) {
        std::vector<std::string> tokens;
        size_t pos = 0;
        std::string delimiter = " ";
        while ((pos = sentences[i].find(delimiter)) != std::string::npos) {
            std::string token = sentences[i].substr(0, pos);
            tokens.push_back(token);
            sentences[i].erase(0, pos + delimiter.length());
        }
        tokens.push_back(sentences[i]);
        sentenceWords.push_back(tokens);
    }
}

std::vector<std::vector<std::string>> Extractor::getExtractedWords() {
    return sentenceWords;
}

#endif /* Extractor_h */
