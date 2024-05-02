#include <bitset>

using namespace std;

static const size_t N = 9;
static const int REG_BITS = 2;

namespace TYPE {
    static constexpr bitset<N> R = 0b001000000;
    static constexpr bitset<N> A = 0b010000000;
    static constexpr bitset<N> B = 0b011000000;
    static constexpr bitset<N> S1 = 0b100000000;
    static constexpr bitset<N> S2 = 0b101000000;
    static constexpr bitset<N> L = 0b110000000;
    static constexpr bitset<N> M = 0b111000000;
    static constexpr bitset<N> E = 0b000000000;
};

namespace OPCODE {
    static constexpr bitset<N> ON = 0b100000, OFF = 0b000000;
};

namespace FUNCT {
    static constexpr bitset<N> ON = 0b10000, OFF = 0b00000;
};

namespace REG {
    static constexpr bitset<N> R0 = 0b0000, R1 = 0b0100, R2 = 0b1000, R3 = 0b1100;
};

unordered_map<string, bitset<N>> regsMap = {
    {"C0", REG::R0}, {"L0", REG::R0}, {"R0", REG::R0},
    {"C1", REG::R1}, {"L1", REG::R1}, {"R1", REG::R1},
    {"C2", REG::R2}, {"L2", REG::R2}, {"R2", REG::R2},
    {"C3", REG::R3}, {"L3", REG::R3}, {"R3", REG::R3}
};