#include "main_random_example.h"

#include "data.h"
#include "random_c_style.h"
#include "random_17.h"
#include "random_23.h"

#include <cstddef>
#include <iostream>

double random_main_c_style_optimized()
{
    const auto n = data2.size();
    const auto rng = new double[n];

    for (size_t i = 0; i < n; ++i)
    {
        rng[i] = data2[i];
    }

    const auto out = random_c_style_optimized(rng, int(n));

    delete[] rng;

    return out;
}

double random_main_17_optimized()
{
    const auto rng = std::vector(data2.begin(), data2.end());
    return random_17_optimized(rng);
}

double random_main_23_optimized()
{
    const auto rng = std::vector(data2.begin(), data2.end());
    return random_23_optimized(rng);
}