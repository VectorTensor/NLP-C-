#include "headers/textProcessing.h"

#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
namespace utils
{
    std::string Process_Text(std::string s)
    {
        std::string result  = s  ;

        // Remove punctuation
        result.erase(std::remove_if(result.begin(), result.end(), ::ispunct), result.end());

      //  char *c ;

        // Convert to lowercase
        std::transform(result.begin(), result.end(),result.begin(),[](char c){return std::tolower(c);});
        return result;
        
        
    }

   void TokenizeText(std::string str )
    {

        std::regex delimiter("\\s* \\s*");
        std::vector<std::string> tokens{
            std::sregex_token_iterator(str.begin(), str.end(), delimiter, -1),
            std::sregex_token_iterator()
        };
        for (const auto& token : tokens) {
            std::cout << token << std::endl;
        }
        
    }
    
}
