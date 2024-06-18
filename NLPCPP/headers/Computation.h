#include <tuple>
#include <tuple>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>
#include <xtensor-blas/xlinalg.hpp>

#define EXP_API __declspec(dllexport)

namespace utils
{

     EXP_API xt::xarray<float>sigmoid(xt::xarray<float>z);
     EXP_API std::tuple<float, xt::xarray<float>> GradientDescent(xt::xarray<float>x , xt::xarray<float>y, xt::xarray<float>theta, float alpha, int num_iters );
    
}
  