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
    // EXP_API torch::Tensor sigmoid(torch::Tensor z);
    // EXP_API std::tuple<float, torch::Tensor> GradientDescent(torch::Tensor x , torch::Tensor y, torch::Tensor theta, float aplha, int num_iters );
}
