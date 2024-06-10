#include "torch/torch.h"
int main(int argc, char* argv[])
{
    torch::Tensor t = torch::rand({2,3});
    char x;
    std::cout << t<<std::endl;
    std::cin>>x;
    
    return 0;
}
