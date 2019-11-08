//
//  main.cpp
//  KWIC
//
// Chilaquiles Pendientes
//

#include <iostream>
#include "Extractor.h"
#include "Rotator.h"
#include "Merger.h"
#include "Sorter.h"

int main(int argc, const char * argv[]) {
    std::cout << "Write each sentence to use, press enter after typing each sentence. Press empty enter when finished." << std::endl;
    
    // Read sentences from console
    std::string sentence;
    std::vector<std::string> sentences;
    while(true) {
        std::getline(std::cin, sentence);
        if (sentence == "") break;
        sentences.push_back(sentence);
    }
    
    // Call first filter and get extracted words from sentences
    Extractor* ext = new Extractor(sentences);

    // Call second filter and pipe it the extracted tokens. Second filter gets all shifts
    // for each token list
    Rotator* rot = new Rotator(ext->getExtractedWords());
    
    // Call third filter with shifted words to merge each shifted sentences into a single string
    Merger* merg = new Merger(rot->getRotatedSentences());
    
    // Last filter sorts the vector of strings in alphabetical order
    Sorter* sor = new Sorter(merg->getMergedSentences());
    std::vector<std::string> sorted = sor->getSorted();
    
    // Print sorted list of strings from the sorter
    std::cout << "Sorted list of strings:" << std::endl;
    for (int i = 0; i < sorted.size(); i++) {
        std::cout << i+1 << ": " << sorted[i] << std::endl;
    }
    
    return 0;
}
