#include <iostream>
#include <tuple>
#include <torch/torch.h>

namespace utils
{

    
   torch::Tensor sigmoid(torch::Tensor z)
   {
   
       torch::Tensor h =1/(1+ torch::exp(-z));
       return h;
       
   }
   
   std::tuple<float, torch::Tensor> GradientDescent(torch::Tensor x , torch::Tensor y, torch::Tensor theta, float aplha, int num_iters )
   {
   
       int m = x.sizes()[0];
       std::tuple<float, torch::Tensor> r;
       return r;
       
       
   } 

    
    
}
