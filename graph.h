#pragma once
#include <bits/stdc++.h>

#define NODES 4
#define R0 0 // R0 is Node 0
#define R1 1 // R1 is Node 1
#define R2 2 // R2 is Node 2
#define R3 3 // R3 is Node 3

extern vector<vector<array<int,2>>> adj;
// Node# -> {Node#, weight}

// Distance and next_hop combined forms routing table
extern array<vector<vector<int>>,2> routing_table;
// routing_table[0] -> Distance (or cost) for each pair (u,v)
// routing_table[1] -> Next hop for each pair(u,v)

struct hash_pair {
    size_t operator()(const pair<int,int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};
extern unordered_map<pair<int,int>,array<int,2>,hash_pair> fec_to_label;
// FEC to label table -> used at the source router
// {source,dest} -> {label,next_hop}

extern vector<unordered_map<int,array<int,2>>> label_swap;
// Label swap table -> used at the destination router
// {label1} -> {label2,next_hop}

#define INGRESS_LABEL 300
#define TRANSIT_LABEL 777

void buildGraph();
void djikstraPerNode(int node);
void buildFECtoLabel(int start, int end);
void buildLabelSwap(int start, int end);