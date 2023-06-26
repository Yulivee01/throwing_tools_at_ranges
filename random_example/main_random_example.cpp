#include "main_random_example.h"

#include "data.h"
#include "random_c_style.h"
#include "random_17.h"
#include "random_23.h"

#include <cstddef>
#include <iostream>

double random_main_c_style()
{
    const auto n = data.size();
    const auto rng = new double[n];

    for (size_t i = 0; i < n; ++i)
    {
        rng[i] = data[i];
    }

    const auto out = random_c_style(rng, int(n));

    delete[] rng;

    return out;
}

double random_main_17()
{
    const auto rng = std::vector(data.begin(), data.end());
    return random_17(rng);
}

double random_main_23()
{
    const auto rng = std::vector(data.begin(), data.end());
    return random_23(rng);
}