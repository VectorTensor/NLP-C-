#include "headers/textProcessing.h"

#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>


namespace utils
{
     std::string cleanCppString(const std::string& input)
    {
        std::string result;
        for (char c : input) {
            if (c >= 32 && c <= 126) {  // Printable ASCII characters range from 32 (space) to 126 (tilde)
                result += c;
            }
        }
        return result;
    }
    std::string Process_Text(std::string s)
    {
        s =cleanCppString(s); 
        std::string result  = s  ;

        // Remove punctuation
        result.erase(std::remove_if(result.begin(), result.end(), ::ispunct), result.end());

      //  char *c ;

        // Convert to lowercase
        std::transform(result.begin(), result.end(),result.begin(),[](char c){return std::tolower(c);});
        return result;
        
        
    }
    
   
    


   std::vector<std::string>TokenizeText(std::string str )
    {

        std::regex delimiter("\\s* \\s*");
        std::vector<std::string> tokens{
            std::sregex_token_iterator(str.begin(), str.end(), delimiter, -1),
            std::sregex_token_iterator()
        };
        // for (const auto& token : tokens) {
        //     tokens.push_back(token);
        //     std::cout << token << std::endl;
        // }
        return tokens; 
        
    }

    std::vector<std::string> ProcessTextNLP(std:: string str)
    {
        std::string preprocessedText = Process_Text(str);
        std::vector<std::string> tokens = TokenizeText(preprocessedText);
        return tokens;
        
    }




    
    
}
