#include "random_23.h"

#include <algorithm>
#include <functional>
#include <ranges>
#include <numeric>

namespace
{
    auto random_23_1(const std::vector<double>& rng)
    {
        return std::views::cartesian_product(
            rng,
            std::views::iota(1, 5),
            rng
                | std::views::transform([](const auto e) { return e * e + 2; }))
                | std::views::transform([](const auto t) 
                    {
                        const auto& [a, b, c] = t;
                        return a * b + 2 * c;
                    });
    }

    auto random_23_2(auto& rng1)
    {
        return std::views::zip_transform(
            [](const auto a, const auto b) { return a / static_cast<double>(b); },
            rng1,
            std::views::iota(10)
        );
    }

    auto random_23_3(auto& rng1, auto& rng2)
    {
        // partial sum
        auto tmp1 = rng1 | std::views::transform([sum = 0.0] (const auto e) mutable { sum += e; return sum; });
        auto tmp2 = rng2
            | std::views::slide(2)
            | std::views::transform([](const auto subrng)
                {
                    return 3.0 * subrng[1] - 2.0 * subrng[0];
                });

        return std::inner_product(std::ranges::begin(tmp1) + 1, std::ranges::end(tmp1), std::ranges::begin(tmp2), 0.0);
    }
}

double random_23_optimized(const std::vector<double>& rng)
{
    auto rng1 = random_23_1(rng);
    auto rng2 = random_23_2(rng1);

    return random_23_3(rng1, rng2);
}
