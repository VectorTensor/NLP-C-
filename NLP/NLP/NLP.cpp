#include "headers/NLPClassificationUtils.h"
#include "headers/textProcessing.h"
int main(int argc, char* argv[])
{
    std::string s = "Hello / ???. how are ";
    auto x = utils::ProcessTextNLP(s);

    for(auto s : x)
    {

        std::cout<<s<<std::endl;
        
    }
     std::vector<std::string>  texts{"Hello how are","this is is it ", "Nobody is the best"};
      std::vector<int> labels{1,1,0};
      
       auto freqs = NLPClassification::BuildFrequencies(texts,labels);
    
    return 0;
}
