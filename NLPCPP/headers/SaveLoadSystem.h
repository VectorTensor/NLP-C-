#include "headers/SentimentModel.h"
#include <string>

namespace SaveAndLoad
{

    void SaveModel(Models::SentimentModel model, std::string path);
    
    Models::SentimentModel LoadModel(std::string path);
    
}
