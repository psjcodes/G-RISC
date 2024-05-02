#include <iostream>
#include <string>
#include <sstream>
#include "ops.hpp"

int main() {
    string input = "MOV R0, R1 \n XOR R0, R3";

    stringstream ss(input);
    string line;
    while (getline(ss, line)) {
        stringstream ls(line);
        string token;
        bitset<N> instr(0b000000000);
        int regNum = 0;
        while (ls >> token) {
            if (token.back() == ',') token.pop_back();

            if (opsMap.count(token)) {
                opsMap[token](instr);
            }
            else if (regsMap.count(token)) {
                instr |= regsMap[token] >> (regNum * REG_BITS);
                regNum++;
            }
            else {
                cerr << "UNEXPECTED TOKEN: " << token << endl;
                return 1;
            }
        }
        cout << instr << endl;
    }

    return 0;
}