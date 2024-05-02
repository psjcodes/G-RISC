#include "masks.hpp"

void MOV(bitset<N> & instr) {
    instr |= TYPE::E | OPCODE::OFF;
}

void CMP(bitset<N> & instr) {
    instr |= TYPE::E | OPCODE::ON;
}

void AND(bitset<N> & instr) {
    instr |= TYPE::R | OPCODE::OFF;
}

void XOR(bitset<N> & instr) {
    instr |= TYPE::R | OPCODE::ON;
}

unordered_map<string, function<void(bitset<N> &)>> opsMap = {
    {"MOV", MOV},
    {"CMP", CMP},
    {"AND", AND},
    {"XOR", XOR}
};

