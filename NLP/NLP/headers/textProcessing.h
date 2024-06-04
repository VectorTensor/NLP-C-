#include <iostream>
#include <regex>
#include <string>
#include <vector>
#define EXP_API __declspec(dllexport)

namespace utils
{
    
    EXP_API void TokenizeText(std::string s);
    EXP_API std::string Process_Text(std::string s);
}
