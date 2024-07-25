#include "masks.hpp"

void MOV (bitset<N> & instr) {
    instr |= TYPE::E | OPCODE::OFF;
}

void CMP (bitset<N> & instr) {
    instr |= TYPE::E | OPCODE::ON;
}

void AND (bitset<N> & instr) {
    instr |= TYPE::R | OPCODE::OFF;
}

void XOR (bitset<N> & instr) {
    instr |= TYPE::R | OPCODE::ON;
}

void BEQ (bitset<N> & instr) {
    instr |= TYPE::B | OPCODE::OFF;
}

void BLT (bitset<N> & instr) {
    instr |= TYPE::B | OPCODE::ON;
}

void ADD (bitset<N> & instr) {
    instr |= TYPE::A | OPCODE::OFF;
}

void SUB (bitset<N> & instr) {
    instr |= TYPE::A | OPCODE::ON;
}

void LSR (bitset<N> & instr) {
    instr |= TYPE::S1 | OPCODE::OFF;
}

void LSL (bitset<N> & instr) {
    instr |= TYPE::S1 | OPCODE::ON;
}

void ASR (bitset<N> & instr) {
    instr |= TYPE::S2 | OPCODE::OFF;
}

void ASL (bitset<N> & instr) {
    instr |= TYPE::S2 | OPCODE::ON;
}

void INC (bitset<N> & instr) {
    instr |= TYPE::L | OPCODE::ON;
}

void DEC (bitset<N> & instr) {
    instr |= TYPE::L | OPCODE::OFF;
}

void LDR (bitset<N> & instr) {
    instr |= TYPE::M | OPCODE::OFF;
}

void STR (bitset<N> & instr) {
    instr |= TYPE::M | OPCODE::ON;
}

unordered_map<string, function<void(bitset<N> &)>> opsMap = {
    {"MOV", MOV},
    {"CMP", CMP},
    {"AND", AND},
    {"XOR", XOR},
    {"BEQ", BEQ},
    {"BLT", BLT},
    {"ADD", ADD},
    {"SUB", SUB},
    {"LSR", LSR},
    {"LSL", LSL},
    {"ASR", ASR},
    {"ASL", ASL},
    {"INC", INC},
    {"DEC", DEC},
    {"LDR", LDR},
    {"STR", STR},
};

