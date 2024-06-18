#include <iostream>
#include <regex>
#include <string>
#include <vector>
#define EXP_API __declspec(dllexport)

namespace utils
{
    
    EXP_API std::vector<std::string> TokenizeText(std::string s);
    EXP_API std::string Process_Text(std::string s);
    EXP_API std::vector<std::string> ProcessTextNLP(std:: string str);
}
