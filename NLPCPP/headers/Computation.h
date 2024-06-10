#include <torch/torch.h>
#define EXP_API __declspec(dllexport)

namespace utils
{

     EXP_API torch::Tensor sigmoid(torch::Tensor z);
     EXP_API std::tuple<float, torch::Tensor> GradientDescent(torch::Tensor x , torch::Tensor y, torch::Tensor theta, float aplha, int num_iters );
    
}
  