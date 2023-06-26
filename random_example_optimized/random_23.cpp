#include "random_23.h"

#include <range/v3/all.hpp>

#include <functional>

namespace
{
    auto random_23_1(const std::vector<double>& rng)
    {
        return ranges::views::cartesian_product(
            rng,
            ranges::views::iota(1, 5),
            rng | ranges::views::transform([](const auto e) { return e * e + 2; }))
            | ranges::views::transform([](const auto t) {
            const auto& [a, b, c] = t;
            return a * b + 2 * c;
                })
            | ranges::to<std::vector>;
    }

    auto random_23_2(auto& rng1)
    {
        return ranges::views::zip_with(
            [](const auto a, const auto b) { return a / static_cast<double>(b); },
            rng1,
            ranges::views::iota(10)
        );
    }

    auto random_23_3(auto& rng1, auto& rng2)
    {
        auto tmp1 = rng1 | ranges::views::partial_sum;
        auto tmp2 = rng2
            | ranges::views::sliding(2)
            | ranges::views::transform([](const auto subrng)
                {
                    return 3.0 * subrng[1] - 2.0 * subrng[0];
                });

        return ranges::inner_product(tmp1 | ranges::views::drop(1), tmp2, 0.0);
    }
}

double random_23_optimized(const std::vector<double>& rng)
{
    auto rng1 = random_23_1(rng);
    auto rng2 = random_23_2(rng1);

    return random_23_3(rng1, rng2);
}