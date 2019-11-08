//
//  Sorter.h
//  KWIC
//
// Chilaquiles Pendientes
//

#ifndef Sorter_h
#define Sorter_h

#include <vector>
#include <string>
#include <algorithm>

/*
 * Sorter. Receives a vector of strings and results in a sorted vector.
 * The sorter is case insensitive.
 */
class Sorter {
    // The resulting sorted vector of strings
    std::vector<std::string> sorted;
    
public:
    Sorter(std::vector<std::string> unsorted);
    std::vector<std::string> getSorted();
};

/*
 * Sorter. Creates a sorted vector of strings, case insensitive by comparing the string characters to lower.
 * @params unsorted. An unsorted vector of strings.
 */
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

/*
 * Getter of the sorted attribute.
 * @return a sorted vector of strings
 */
std::vector<std::string> Sorter::getSorted() {
    return sorted;
}

#endif /* Sorter_h */
