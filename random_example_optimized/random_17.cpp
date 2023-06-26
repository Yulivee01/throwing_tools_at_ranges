#include "random_17.h"

#include <algorithm>
#include <array>
#include <numeric>
#include <iostream>

namespace
{
    auto random_17_1(const std::vector<double>& rng)
    {
        auto out = std::vector<double>(rng.size() * rng.size() * 4);
        for (size_t i = 0; const auto e1 : rng)
        {
            for (int j = 1; j < 5; ++j)
            {
                const auto temp1 = e1 * j;
                for (const auto e3 : rng)
                {
                    out[i++] = temp1 + 2 * (e3 * e3 + 2);
                }
            }
        }

        return out;
    }

    auto random_17_2(const std::vector<double>& rng)
    {
        auto out = std::vector<double>(rng.size());
        double i = -1.0;
        std::transform(rng.begin(), rng.end(), out.begin(), [&](const auto e)
            {
                i += 1.0;
                return e / (i + 10.0);
            });

        return out;
    }

    auto random_17_3(const std::vector<double>& rng1, const std::vector<double>& rng2)
    {
        double prev = rng1[0];
        size_t i = 0;
        return std::accumulate(rng1.begin() + 1, rng1.end(), 0.0,
            [&](const auto sum, const auto cur)
            {
                prev += cur;
                ++i;
                return sum + prev * (3.0 * rng2[i] - 2.0 * rng2[i - 1]);
            });
    }
}

double random_17_optimized(const std::vector<double>& rng)
{
    const auto rng1 = random_17_1(rng);
    const auto rng2 = random_17_2(rng1);
    return random_17_3(rng1, rng2);
}