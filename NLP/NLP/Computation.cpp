#include <iostream>
#include <torch/torch.h>


namespace utils
{

    
   torch::Tensor sigmoid(torch::Tensor z)
   {

       torch::Tensor h =1/(1+ torch::exp(-z));
       return h;
       
       
   }
    
}
