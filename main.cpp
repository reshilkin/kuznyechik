#include "coder.h"
#include <chrono>
#include <iostream>



int main(int argc, char* argv[])
{
    auto k = keys({});
    auto block = block_t{};

    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    auto t1 = high_resolution_clock::now();
    for (size_t i = 0; i < 100 * 1024 * 1024 / sizeof(block_t); i++) {
        encode(block, k);
    }
    auto t2 = high_resolution_clock::now();
    duration<double, std::milli> ms_double = t2 - t1;
    std::cout << (uint32_t)block[0] << std::endl;
    std::cout << ms_double.count() << "ms\n";
}