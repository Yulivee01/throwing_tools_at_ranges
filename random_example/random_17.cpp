#include "random_17.h"

#include <algorithm>
#include <array>
#include <numeric>

namespace
{
    auto random_17_1(const std::vector<double>& rng)
    {
        auto out = std::vector<double>();
        out.reserve(rng.size() * rng.size() * 4);
        for (const auto e1 : rng)
        {
            for (const auto e2 : std::array{ 1, 2, 3, 4 })
            {
                for (const auto e3 : rng)
                {
                    const auto e = e1 * e2 + 2 * (e3 * e3 + 2);
                    out.push_back(e);
                }
            }
        }

        return out;
    }

    auto random_17_2(const std::vector<double>& rng)
    {
        auto out = std::vector<double>(rng.size());
        int i = 0;
        std::transform(rng.begin(), rng.end(), out.begin(), [&](const auto e)
            {
                return e / (static_cast<double>(i++) + 10.0);
            });

        return out;
    }

    auto random_17_3(const std::vector<double>& rng1, const std::vector<double>& rng2)
    {
        auto tmp1 = std::vector<double>(rng1.size());
        std::partial_sum(rng1.begin(), rng1.end(), tmp1.begin());

        auto tmp2 = std::vector<double>(rng2.size());
        std::adjacent_difference(rng2.begin(), rng2.end(), tmp2.begin(), [](const auto left, const auto right)
            {
                return 3.0 * left - 2.0 * right;
            });

        return std::inner_product(tmp1.begin() + 1, tmp1.end(), tmp2.begin() + 1, 0.0);
    }
}

double random_17(const std::vector<double>& rng)
{
    const auto rng1 = random_17_1(rng);
    const auto rng2 = random_17_2(rng1);
    return random_17_3(rng1, rng2);
}