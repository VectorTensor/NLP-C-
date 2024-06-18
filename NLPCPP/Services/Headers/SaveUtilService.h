#include <fstream>
#include <unordered_map>
#include "../../headers/NLPClassificationUtils.h"

namespace SaveUtilService
{
     void SaveFreqTable(std::ofstream& outFile, std::unordered_map<std::tuple<std:: string,int>,int, NLPClassification::tuple_hash> freq);
        std::unordered_map<std::tuple<std::string, int>, int, NLPClassification::tuple_hash> LoadFreqTable(std::ifstream& inFile);

    void SaveTheta(std::ofstream& outFile, xt::xarray<float> theta);
    xt::xarray<float> LoadTheta(std::ifstream& inFile);
}
