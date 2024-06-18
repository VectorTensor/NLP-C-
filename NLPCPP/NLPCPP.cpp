#include "headers/Computation.h"
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>
#include <xtensor-blas/xlinalg.hpp>
#include <xtensor/xnpy.hpp>
#include <csv.hpp>
#include "headers/SaveLoadSystem.h"
#include "headers/NLPClassificationUtils.h"
void Test();


int main(int argc, char* argv[])
{
 //    xt::xarray<float> x = xt::xarray<float>({{0.45238, 0.48282, 0.2183},
 // {0.975 ,0.667423 ,0.0890},
 // {0.4948 ,0.7617 ,0.6096},
 // {0.04428 ,0.9753  ,0.3036},
 // {0.7608 ,0.4687 ,0.952 },
 // {0.47371 ,0.0951 ,0.425 },
 // {0.9931 ,0.8238,0.3365},
 // {0.0557 ,0.6187 ,0.6749 },
 // {0.3952 ,0.4031  ,0.5836},
 // {0.8194 ,0.7394, 0.2167}});
 //     xt::xarray<float> y = xt::ones<float>({10,1});
 //    xt::xarray<float> t = xt::xarray<float>({{0.360,0.361,0.8937}});
 //    auto p = utils::GradientDescent(x,y,xt::transpose(t),0.001,10);
 //    std::cout << std::get<0>(p)<<std::endl;
 //    std::cout << std::get<1>(p)<<std::endl;
 //
 //     std::unordered_map<std::tuple<std:: string,int>,int, NLPClassification::tuple_hash> freq ;
 //    freq[{"a",0}] = 2;
 //    freq[{"b",0}] = 2;
 //    freq[{"a",1}] = 4;
 //    freq[{"b",1}] = 3;
 //    freq[{"c",0}] = 2;
 //    freq[{"c",1}] = 6;
 //    freq[{"d",0}] = 3;
 //    auto freat = NLPClassification::ExtractFeatures("a c b c", freq);
 //    std::cout << freat;
 // //
 //    xt::xarray<float> x = xt::xarray<float>({1.2f,2,2.5});
 //    xt::dump_npy("test.npy",x);
 //    auto data = xt::load_npy<float>("test.npy");
 //    std::cout << data;
  Test();
   

    
    char m;
    std::cin >> m ;

    return 0;
}

void Test()
{

    using namespace csv;
    CSVReader reader("dataset/trainProcessed.csv");

    std::vector<std::string> texts;
    std::vector<float> sentiments;
    for(CSVRow& row:reader )
    {

        std::cout<<row.get_col_names()[1]<<std::endl;
        std::cout<<row.get_col_names()[2]<<std::endl;
        std::cout<<row.get_col_names()[3]<<std::endl;

        auto text =row["text"].get<std::string>();
        auto sent = row["sentiment"].get<float>();
        texts.push_back(text);

        sentiments.push_back(sent);
        
    }

    Models::SentimentModel sm(0.00001f,1500);
    sm.Fit(texts,sentiments);
    std::cout << "finished"<<std::endl;
    std::vector<std::string> test_s = {"Is that really all you left me? @ GearboxOfficial @ Borderlands pic.fm / X4oKeH4TMH"};
    std::cout << sm.Predict(test_s)<<std::endl;
    std::cout<<sm.GetTheta()<<std::endl;    

    SaveAndLoad::SaveModel(sm,"model1.bin");
    Models::SentimentModel t;
    
    std::cout << "empty model"<<std::endl;
    std::cout<< t.GetTheta()<<std::endl;
    auto loadsm = SaveAndLoad::LoadModel("model1.bin");

    std::cout<<sm.GetTheta()<<std::endl;
    std::cout<<loadsm.GetTheta()<<std::endl;
    
    
    

    

    
    
}
