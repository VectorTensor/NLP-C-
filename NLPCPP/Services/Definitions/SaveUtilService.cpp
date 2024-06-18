#include "../Headers/SaveUtilService.h"

namespace SaveUtilService 
{
    /**
  * Saves the frequency table to the output file stream in binary format.
  *
  * @param outFile The output file stream to write the frequency table to.
  * @param freq The frequency table to be saved, represented as an unordered map with keys as tuples of
  *             (std::string, int) and values as ints.
  *
  * @throws None
  */ 
    void SaveFreqTable(std::ofstream& outFile,
                       std::unordered_map<std::tuple<std::string, int>, int, NLPClassification::tuple_hash> freq)
    {
        size_t size = freq.size();
        outFile.write(reinterpret_cast<char*>(&size), sizeof(size));

        // Write each key-value pair to the binary file
        for (const auto& pair : freq) {
            const auto& key = pair.first;
            const std::string& str = std::get<0>(key);
            int number = std::get<1>(key);
            int value = pair.second;

            size_t strLength = str.size();
            outFile.write(reinterpret_cast<char*>(&strLength), sizeof(strLength));
            outFile.write(str.c_str(), strLength);
            outFile.write(reinterpret_cast<char*>(&number), sizeof(number));
            outFile.write(reinterpret_cast<char*>(&value), sizeof(value));
        }

    }
    /**
 * Reads and loads frequency table data from the input file stream.
 *
 * @param inFile The input file stream to read the data from.
 *
 * @return The loaded frequency table as an unordered map.
 *
 * @throws None
 */
    std::unordered_map<std::tuple<std::string, int>, int, NLPClassification::tuple_hash> LoadFreqTable(std::ifstream& inFile)
    {

        std::unordered_map<std::tuple<std::string, int>, int, NLPClassification::tuple_hash> freq;
        size_t size;
        inFile.read(reinterpret_cast<char*>(&size), sizeof(size));
        for (size_t i = 0; i < size; ++i) {
            std::string str;
            int number;
            int value;
            size_t strLength;
            inFile.read(reinterpret_cast<char*>(&strLength), sizeof(strLength));
            str.resize(strLength);
            inFile.read(&str[0], strLength);
            inFile.read(reinterpret_cast<char*>(&number), sizeof(number));
            inFile.read(reinterpret_cast<char*>(&value), sizeof(value));
            freq[std::make_tuple(str, number)] = value;
        }
        return freq;    
    }

    void SaveTheta(std::ofstream& outFile, xt::xarray<float> theta)
    {
        auto shape = theta.shape();
        size_t shapeSize = shape.size();
        outFile.write(reinterpret_cast<const char*>(&shapeSize), sizeof(shapeSize));
        outFile.write(reinterpret_cast<const char*>(shape.data()), shapeSize * sizeof(size_t));

        // Write the data of the array
        outFile.write(reinterpret_cast<const char*>(theta.data()), theta.size() * sizeof(float));

    }

    xt::xarray<float> LoadTheta(std::ifstream& inFile)
    {

        xt::xarray<float> theta;
        size_t shapeSize;
        inFile.read(reinterpret_cast<char*>(&shapeSize), sizeof(shapeSize));
        std::vector<size_t> shape(shapeSize);
        inFile.read(reinterpret_cast<char*>(shape.data()), shapeSize * sizeof(size_t));
        theta.resize(shape);
        inFile.read(reinterpret_cast<char*>(theta.data()), theta.size() * sizeof(float));
        return theta;
        
    }
}
