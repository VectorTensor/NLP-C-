#include <iostream>
#include "headers/Computation.h"

namespace utils
{

    
   xt::xarray<float>sigmoid(xt::xarray<float>z)
   {
       
       xt::xarray<float>h = 1/(1+ xt::exp(-z));
       return h;
       
   }
   
   std::tuple<float, xt::xarray<float>> GradientDescent(xt::xarray<float> x , xt::xarray<float>y, xt::xarray<float>theta, float alpha, int num_iters )
   {

       auto m = x.shape()[0];
       std::tuple<float, xt::xarray<float>> r;
       xt::xarray<float> J;
       for (int i =0;i< num_iters;i++)
       {

           xt::xarray<float>z = xt::linalg::dot(x,theta);
           xt::xarray<float> h = utils::sigmoid(z);
            J = -(xt::linalg::dot(xt::transpose(y),xt::log(h)) + xt::linalg::dot(xt::transpose(1-y),xt::log(1-h)))/m;
           theta = theta - alpha*(xt::linalg::dot(xt::transpose(x),(h-y)))/m;
           std::cout << theta<<std::endl;
           
           
       }
       r = {J[0],theta};
       
       return r;
       
       
   } 

    
    
}
