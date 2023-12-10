#include <cstdint>
#include <vector>
#include <array>

using block_t = std::array<uint8_t, 16>;

std::array<block_t, 10> keys(const std::array<uint8_t, 32>& k);

void encode(block_t& data, const std::array<block_t, 10>& keys);
