#include "headers/SaveLoadSystem.h"
#include <fstream>

#include "Services/Headers/SaveUtilService.h"
/*
 * Important
 * so to save the unordered map you need to do a lot more so i am pausing this look in chatgpt 
 *
 */

namespace SaveAndLoad 
{
    /**
  * Saves a SentimentModel object to a binary file specified by the given path.
  *
  * @param model The SentimentModel object to be saved.
  * @param path The path to the file where the model will be saved.
  *
  * @throws None
  */ 
    void SaveModel(Models::SentimentModel model, std::string path)
    {

        std::ofstream outFile(path , std::ios::binary);

        // Check if the file opened successfully
        if (!outFile) {
            std::cerr << "Error opening file for writing" << std::endl;
        }
        ModelDto::SentimentDto dto = model.ToDto();

        // Write the object to the binary file
        outFile.write(reinterpret_cast<char*>(&dto), sizeof(ModelDto::SentimentDto));
        SaveUtilService::SaveFreqTable(outFile, model.GetFreqs());
        SaveUtilService::SaveTheta(outFile,model.GetTheta());
        
        
        // Close the file
        
        outFile.close();
        
    }
    /**
     * Loads a SentimentModel object from a binary file specified by the given path.
     *
     * @param path The path to the file where the model is stored.
     *
     * @return The loaded SentimentModel object.
     *
     * @throws std::invalid_argument if the file cannot be opened or if the loaded data is invalid.
     */
    Models::SentimentModel LoadModel(std::string path)
    {

        std::ifstream inFile(path, std::ios::binary);
        if (!inFile) {
            std::cerr << "Error opening file for reading" << std::endl;
        }
        ModelDto::SentimentDto dto;
        inFile.read(reinterpret_cast<char*>(&dto), sizeof(ModelDto::SentimentDto));
        auto freqs = SaveUtilService::LoadFreqTable(inFile);
        auto theta = SaveUtilService::LoadTheta(inFile);
        inFile.close();
        Models::SentimentModel model = Models::SentimentModel(dto,freqs,theta);

        
        
        return model;   
      
    }
   
    
}
