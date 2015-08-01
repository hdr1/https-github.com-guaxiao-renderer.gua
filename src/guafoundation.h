#ifndef __Gua__guafoundation__
#define __Gua__guafoundation__


#include <vector>
#include <string>


static std::vector<std::string>
split(const std::string &str, char delimiter) {
    std::vector<std::string> l;
    
    std::size_t start = 0;
    std::size_t end = 0;
    
    while ((end = str.find(delimiter, start)) != std::string::npos) {
        l.push_back(str.substr(start, end - start));
        start = end + 1;
    }
    l.push_back(str.substr(start));
    
    return l;
}

#endif
