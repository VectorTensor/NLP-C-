#include "headers/textProcessing.h"
int main(int argc, char* argv[])
{
    std::string s = "Hello / ???. how are ";
    s = utils::Process_Text(s);
    utils::TokenizeText(s);
    
    return 0;
}
