#include "random_c_style.h"

namespace
{
    double* random_c_style_1(double* rng, int n)
    {
        double* out = new double[n * n * 4];

        int ii = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 1; j < 5; ++j)
            {
                for (int k = 0; k < n; ++k)
                {
                    out[ii] = rng[i] * j + 2 * (rng[k] * rng[k] + 2);
                    ++ii;
                }
            }
        }

        return out;
    }

    double* random_c_style_2(double* rng, int n)
    {
        double* out = new double[n];
        for (int i = 0; i < n; ++i)
        {
            out[i] = rng[i] / (double(i) + 10.0);
        }

        return out;
    }

    double random_c_style_3(double* rng1, double* rng2, int n)
    {
        double* tmp1 = new double[n];
        tmp1[0] = rng1[0];
        for (int i = 1; i < n; ++i)
        {
            tmp1[i] = tmp1[i - 1] + rng1[i];
        }

        double* tmp2 = new double[n - 1];
        for (int i = 0; i < n - 1; ++i)
        {
            tmp2[i] = 3.0 * rng2[i + 1] - 2.0 * rng2[i];
        }

        double sum = 0.0;
        for (int i = 0; i < n - 1; ++i)
        {
            sum += tmp1[i + 1] * tmp2[i];
        }

        delete[] tmp1;
        delete[] tmp2;

        return sum;
    }
}

double random_c_style(double* rng, int n)
{
    const auto tmp1 = random_c_style_1(rng, n);
    const auto tmp2 = random_c_style_2(tmp1, n * n * 4);
    const auto out = random_c_style_3(tmp1, tmp2, n * n * 4);

    delete[] tmp1;
    delete[] tmp2;

    return out;
}