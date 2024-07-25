#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "ops.hpp"

bool is_valid_label (string token) {
    return token.size() > 2 && token.back() == ':';
}

int main (int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    string fn = argv[1];
    ifstream inputFile(fn);
    if (!inputFile) {
        cerr << "Error: Unable to open file " << argv[1] << endl;
        return 1;
    }

    ofstream outputFile(fn + "_out");
    if (!outputFile) {
        cerr << "Error: Unable to create output file" << endl;
        return 1;
    }

    unordered_map<string, uint8_t> branchMap;
    uint8_t branchNum = 0;

    string line;
    // first pass for branch labels
    while (getline(inputFile, line)) {
        stringstream ls(line);
        string token;
        while (ls >> token) {
            if (is_valid_label(token)) {
                if (branchNum >= 32) {
                    cerr << "Exceed JLUT size (32)" << endl;
                }
                branchMap[token] = branchNum++;
            }
        } 
    }

    inputFile.clear();
    inputFile.seekg(0, ios::beg);

    int lineNum = 0;
    // second pass for instructions
    while (getline(inputFile, line)) {
        stringstream ls(line);
        string token;
        bitset<N> instr(0b000000000); // 9 bits
        int regNum = 0;
        bool isLabel = false;
        while (ls >> token) {
            if (token.back() == ',') token.pop_back();

            if (opsMap.count(token)) {
                opsMap[token](instr);
                // handle branch instructions
                if (token == "BEQ" || token == "BLT") {
                    ls >> token;
                    token += ":";
                    instr |= bitset<N>(branchMap[token]);
                }
            }
            else if (regsMap.count(token)) {
                // handle register tokens
                instr |= regsMap[token] >> (regNum * REG_BITS);
                regNum++;
                // set func bit to 1 for loop counter regs and immediate values
                if (token.front() == '#' || token.front() == 'L') {
                    instr |= FUNCT::ON;
                }
            }
            else if (is_valid_label(token)) {
                isLabel = true;
                cout << token << " " << lineNum + 1 << endl;
            }
            else {
                cerr << "Unexpected token: " << token << " on line " << lineNum << endl;
                return 1;
            }
        }
        if (isLabel) continue;
        if (lineNum > 0) outputFile << '\n';
        outputFile << instr;
        lineNum++;
    }

    inputFile.close();
    outputFile.close();
    return 0;
}