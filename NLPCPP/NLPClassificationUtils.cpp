#include <iostream>
#include <unordered_map>
#include<vector>
#include<tuple>
#include"headers/textProcessing.h"
#include"headers/NLPClassificationUtils.h"
#define EXP_API __declspec(dllexport)

namespace NLPClassification
{

   EXP_API std::unordered_map<std::tuple<std:: string,int>,int,tuple_hash> BuildFrequencies(std::vector<std::string> text, std::vector<int> y)
    {
        std:: unordered_map<std::tuple<std::string, int>,int,tuple_hash> freqs = {} ;
        
        

        for(int i= 0;i<text.size();i++)
        {

            auto tokens = utils::ProcessTextNLP(text[i]);

            for (auto token: tokens)
            {

                std::tuple<std::string,int> pair = {token,y[i]};
                if(freqs.contains(pair))
                {

                    freqs[pair] +=1 ;
                    
                }
                else
                {

                    freqs[pair] =1;
                    
                }
                
            }
            
        }
        return freqs;
        
    }
    
    
}
