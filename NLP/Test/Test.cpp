#include "Helloer.h"

#include "csv.hpp"
using namespace csv;
int main(int argc, char* argv[])
{

    CSVReader reader("dataset/data.csv");
    for (CSVRow& row: reader)
    {
        // Input iterator
        std:: cout<< row["a"].get<int>()<<std::endl; 
    }
    
    return 0;
}
