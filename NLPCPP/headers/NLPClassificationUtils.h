#pragma once

#include<iostream>
#include <unordered_map>
#include<vector>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>
#include <xtensor-blas/xlinalg.hpp>


#define EXP_API __declspec(dllexport)

namespace NLPClassification 
{
    
    struct tuple_hash {
        template <class T1, class T2>
        std::size_t operator() (const std::tuple<T1, T2>& t) const {
            auto hash1 = std::hash<T1>{}(std::get<0>(t));
            auto hash2 = std::hash<T2>{}(std::get<1>(t));
            return hash1 ^ (hash2 << 1); // Combine hashes
        }
    }; 

    EXP_API std::unordered_map<std::tuple<std:: string,int>,int,tuple_hash> BuildFrequencies(std::vector<std::string> text, std::vector<int> y);
    
    EXP_API xt::xarray<float> ExtractFeatures(std::string text,  std:: unordered_map<std::tuple<std::string, int>,int,tuple_hash> freqs);
    
    EXP_API xt::xarray<float> PredictSentiment(std::string text,std::unordered_map<std::tuple<std:: string,int>,int,tuple_hash> freqs, xt::xarray<float> theta);

    EXP_API xt::xarray<float> TrainModel(xt::xarray<float> x, xt::xarray<float> y, float alpha, int num_iters);
}



