#include "..\headers\ModelDto.h"

namespace ModelDto
{

    ModelDto::SentimentDto::SentimentDto(float alpha, int n)
    {
        m_alpha_ = alpha;
        _num_iters = n;
    }

    SentimentDto::SentimentDto()
    {
    }
}
