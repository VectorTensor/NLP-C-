#include <iostream>
#include <unordered_map>
#include<vector>
#include<tuple>
#include"headers/textProcessing.h"
#include"headers/NLPClassificationUtils.h"

#include "headers/Computation.h"
#define EXP_API __declspec(dllexport)

namespace NLPClassification
{

   std::unordered_map<std::tuple<std:: string,int>,int,tuple_hash> BuildFrequencies(std::vector<std::string> text, std::vector<int> y)
    {
        std:: unordered_map<std::tuple<std::string, int>,int,tuple_hash> freqs = {} ;

       if(text.size() != y.size())
       {
           std::cout << "The size of input and output is different"<<std::endl;
           std::cout<<text.size()<<std::endl;
           std::cout<<y.size()<<std::endl;
           
       }

       

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
            std::cout << i<<std::endl;
            
        }
        return freqs;
        
    }

    xt::xarray<float> ExtractFeatures(std::string text,  std:: unordered_map<std::tuple<std::string, int>,int,tuple_hash> freqs)
   {

       auto word_l = utils::ProcessTextNLP(text);
       xt::xarray<float> x = xt::zeros<float>({3});
       x[0] = 1;


       for (auto w : word_l)
       {
           if(freqs.contains({w,1.0}))
           {

               x[1]+= freqs[{w,1.0}];
               
           }
           else
           {

               x[1] +=0;
               
           }
           
           if(freqs.contains({w,0.0}))
           {

               x[2]+= freqs[{w,0.0}];
               
           }
           else
           {

               x[2] +=0;
               
           }
       }


       return x;
       
       
   }

    xt::xarray<float> PredictSentiment(std::string text,std::unordered_map<std::tuple<std:: string,int>,int,tuple_hash> freqs, xt::xarray<float> theta)
   {

       auto x = ExtractFeatures(text, freqs);
       auto y_pred = utils::sigmoid(xt::linalg::dot(x,theta));

       return y_pred;
       
   }

    xt::xarray<float> TrainModel(xt::xarray<float> x, xt::xarray<float> y, float alpha, int num_iters)
   {

       xt::xarray<float> theta = xt::zeros<float>({x.shape()[1]});
       auto gredDesc = utils::GradientDescent(x,y,theta,alpha,num_iters);
       theta = std::get<1>(gredDesc);
       //std::cout << theta<<std::endl;
       return theta;
       
   }

    
    

    
    
    
}
