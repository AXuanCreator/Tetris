//
// Created by AXuan on 2023/5/11.
//

#include "randomgen.h"

RandomGen::RandomGen():gen(rd()) {
}

RandomGen::~RandomGen() = default;


int RandomGen::blockCreatRandom(){

    std::uniform_int_distribution<> dis(1,5);
    return dis(gen);
}



