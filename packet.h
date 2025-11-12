#pragma once
#include <bits/stdc++.h>

#define EMPTY_LABEL -1

// Packet class for simulation
class Packet{
public:
    int source;
    int destination;
    int label;
};

int forwardPacket(int& router, Packet& packet, FILE* file);