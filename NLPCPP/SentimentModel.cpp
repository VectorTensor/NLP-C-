#include <csv.hpp>
#include <xtensor/xnpy.hpp>
#include "headers/SentimentModel.h"
#include <fstream>

namespace Models
{

    SentimentModel::SentimentModel(float alpha, int num_iters)
    {
        m_alpha_ = alpha;
        _num_iters = num_iters;
        
    }
    SentimentModel::SentimentModel( std::unordered_map<std::tuple<std:: string,int>,int, NLPClassification::tuple_hash> freq)
    {

        _freqs = freq;
        
    }

    SentimentModel::SentimentModel()
    {
    }

    SentimentModel* SentimentModel::Fit(std::vector<std::string> texts, std::vector<float> y)
    {
        std::vector<int> y_int(y.begin(),y.end());
        std::unordered_map<std::tuple<std:: string,int>,int, NLPClassification::tuple_hash> freqs =  NLPClassification::BuildFrequencies(texts,y_int);
        _freqs = freqs;
        auto si = texts.size();
        xt::xarray<float> x = xt::zeros<float>({(int) si,3});
        for(int i =0;i<(int)texts.size();i++)
        {

            xt::row(x,i) = NLPClassification::ExtractFeatures(texts[i],freqs);

            std::cout << i<<std::endl;
        }
        xt::xarray<float> y_vec = xt::adapt(y);
        m_theta = NLPClassification::TrainModel(x,y_vec,m_alpha_,_num_iters);
        return this;
        
    }

    xt::xarray<float> SentimentModel::Predict(std::vector<std::string> texts)
    {
        xt::xarray<float>sents = xt::zeros<float>({ texts.size() });

        int i =0;
        for(auto text:texts)
        {

            //NLPClassification::PredictSentiment(text,_freqs,m_theta);
            sents[i] = (NLPClassification::PredictSentiment(text,_freqs,m_theta)[0]);
            i++;
            
            
        }

        return sents;

        
    }

    float SentimentModel::TestAccuracy(std::vector<std::string> texts , xt::xarray<float> y)
    {


        int total = texts.size();
        int count =0;
        auto Y_pred = Predict(texts);
        for (int i =0 ;i<(int)texts.size();i++)
        {

            float e = 0.001f;
            float diff = Y_pred[i] - y[i];
            if (fabs(diff) < e)
            {
                count ++;
            }

        }
        float accuracy = count/(float)total;
        return accuracy;
    }

    xt::xarray<float> SentimentModel::GetTheta()
    {

        return m_theta; 
    }

    ModelDto::SentimentDto SentimentModel::ToDto()
    {
        ModelDto::SentimentDto dto(m_alpha_,_num_iters);
        return dto;
        
    }

    std::unordered_map<std::tuple<std::string, int>, int, NLPClassification::tuple_hash> SentimentModel::GetFreqs()
    {

        return _freqs;
    }

    SentimentModel::SentimentModel(ModelDto::SentimentDto dto, std::unordered_map<std::tuple<std:: string,int>,int, NLPClassification::tuple_hash> freq,xt::xarray<float> theta)
    {
        m_alpha_ = dto.m_alpha_;
        _num_iters = dto._num_iters;
        _freqs = freq;
        m_theta = theta;
    }
}
