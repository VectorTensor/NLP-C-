#pragma once
#include "headers/Computation.h"
#include "headers/ModelDto.h"
#include "headers/textProcessing.h"
#include "headers/NLPClassificationUtils.h"

namespace Models
{
    class SentimentModel
    {
    private:
        float m_alpha_;
        int _num_iters;
        xt::xarray<float> m_theta;
        std::unordered_map<std::tuple<std:: string,int>,int, NLPClassification::tuple_hash> _freqs;

        
    public:
        SentimentModel( float alpha, int num_iters);
        SentimentModel( std::unordered_map<std::tuple<std:: string,int>,int, NLPClassification::tuple_hash> freq);
        SentimentModel();
        SentimentModel* Fit(std::vector<std::string> texts , std::vector<float> y);
        xt::xarray<float> Predict(std::vector<std::string> texts);
        float TestAccuracy(std::vector<std::string> texts , xt::xarray<float> y);
        xt::xarray<float> GetTheta();
        ModelDto::SentimentDto ToDto();
         std ::unordered_map<std::tuple<std:: string,int>,int, NLPClassification::tuple_hash> GetFreqs();
        SentimentModel(ModelDto::SentimentDto dto,
                       std::unordered_map<std::tuple<std::string, int>, int, NLPClassification::tuple_hash> freq,xt::xarray<float> theta);
    };

    
    
}
