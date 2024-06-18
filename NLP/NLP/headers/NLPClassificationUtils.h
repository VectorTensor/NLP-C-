#include<iostream>
#include <unordered_map>
#include<vector>

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
    
}



