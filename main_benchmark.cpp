//#include <benchmark/benchmark.h>
//#include "random_example/main_random_example.h"
//
//#include "random_example/random_c_style.h"
//#include "random_example/random_17.h"
//#include "random_example/random_23.h"
//#include "random_example/data.h"
//
//#include "random_example_optimized/random_c_style.h"
//#include "random_example_optimized/random_17.h"
//#include "random_example_optimized/random_23.h"
//
//#include <cstddef>
//
//static void c_style_benchmark(benchmark::State& state) 
//{
//    const auto n = data.size();
//    const auto rng = new double[n];
//
//    for (size_t i = 0; i < n; ++i)
//    {
//        rng[i] = data[i];
//    }
//
//    for (auto _ : state)
//    {
//        benchmark::DoNotOptimize(random_c_style(rng, int(n)));
//    }
//
//    delete[] rng;
//}
//
//static void cpp_17_benchmark(benchmark::State& state) 
//{
//    const auto rng = std::vector(data.begin(), data.end());
//    for (auto _ : state)
//    {
//        benchmark::DoNotOptimize(random_17(rng));
//    }
//}
//
//static void cpp_23_benchmark(benchmark::State& state) 
//{
//    const auto rng = std::vector(data.begin(), data.end());
//    for (auto _ : state)
//    {
//        benchmark::DoNotOptimize(random_23(rng));
//    }
//}
//
//static void c_style_benchmark_optimized(benchmark::State& state) 
//{
//    const auto n = data.size();
//    const auto rng = new double[n];
//
//    for (size_t i = 0; i < n; ++i)
//    {
//        rng[i] = data[i];
//    }
//
//    for (auto _ : state)
//    {
//        benchmark::DoNotOptimize(random_c_style_optimized(rng, int(n)));
//    }
//
//    delete[] rng;
//}
//
//static void cpp_17_benchmark_optimized(benchmark::State& state)
//{
//    const auto rng = std::vector(data.begin(), data.end());
//    for (auto _ : state)
//    {
//        benchmark::DoNotOptimize(random_17_optimized(rng));
//    }
//}
//
//static void cpp_23_benchmark_optimized(benchmark::State& state)
//{
//    const auto rng = std::vector(data.begin(), data.end());
//    for (auto _ : state)
//    {
//        benchmark::DoNotOptimize(random_23_optimized(rng));
//    }
//}
//
//BENCHMARK(c_style_benchmark)->Unit(benchmark::kMillisecond);
//BENCHMARK(cpp_17_benchmark)->Unit(benchmark::kMillisecond);
//BENCHMARK(cpp_23_benchmark)->Unit(benchmark::kMillisecond);
//
//BENCHMARK(c_style_benchmark_optimized)->Unit(benchmark::kMillisecond);
//BENCHMARK(cpp_17_benchmark_optimized)->Unit(benchmark::kMillisecond);
//BENCHMARK(cpp_23_benchmark_optimized)->Unit(benchmark::kMillisecond);
//
//BENCHMARK_MAIN();