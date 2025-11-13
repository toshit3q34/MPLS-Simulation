#include "graph.h"

void buildGraph(){
    adj.assign(NODES,{});
    routing_table[0].assign(NODES,vector<int>(NODES,INT_MAX));
    routing_table[1].assign(NODES,vector<int>(NODES,-1));
    label_swap.assign(NODES,{});

    adj[0].push_back({1,10}); adj[1].push_back({0,10});
    adj[0].push_back({2,20}); adj[2].push_back({0,20});
    adj[1].push_back({3,20}); adj[3].push_back({1,20});
    adj[2].push_back({3,10}); adj[3].push_back({2,10});
}

void djikstraPerNode(int u){
    set<array<int,2>> pq;
    vector<int>& distance = routing_table[0][u];
    vector<int>& next_hop = routing_table[1][u];
    distance[u] = 0;
    next_hop[u] = -1;
    pq.insert({0,u});

    while (!pq.empty())
    {
        auto temp = *pq.begin();
        pq.erase(pq.begin());

        int curr = temp[0];
        int node = temp[1];

        for(auto &[i,w] : adj[node]){
            if(curr + w <= distance[i]){
                pq.erase({distance[i],i});
                distance[i] = curr + w;
                next_hop[i] = next_hop[node];
                if(next_hop[i] == -1) next_hop[i] = i;
                pq.insert({distance[i],i});
            }
        }
    }
}

void buildFECtoLabel(int u, int v){
    // Here we will only do for {u=R0, v=R3} as asked in question
    fec_to_label[{u,v}] = {INGRESS_LABEL,routing_table[1][u][v]};
}

void buildLabelSwap(int u, int v){
    // Here we will only do for {u=R0, v=R3} as asked in question
    auto [curr_label, curr_node] = fec_to_label[{u,v}];
    while (curr_node != v)
    {
        label_swap[curr_node][curr_label] = {TRANSIT_LABEL,routing_table[1][curr_node][v]};
        curr_label = TRANSIT_LABEL;
        curr_node = routing_table[1][curr_node][v];
    }
}

void printRoutingTables(FILE* file) {
    for (int u = 0; u < NODES; u++) 
    {
        fprintf(file, "Routing Table for Router R%d:\n", u);
        fprintf(file, "Destination | Next Hop | Total Cost\n");
        fprintf(file, "------------------------------------\n");
        for (int v = 0; v < NODES; v++) {
            int cost = routing_table[0][u][v];
            int next = routing_table[1][u][v];
            if (cost == INT_MAX) {
                fprintf(file, "R%d  |    -    |      INF\n", v);
                continue;
            }
            if (u == v) {
                fprintf(file, "R%d  |    R%d    |    %d\n", v, u, cost);
            } else {
                fprintf(file, "R%d  |    R%d    |    %d\n", v, next, cost);
            }
        }
        fprintf(file, "\n");
    }
}

vector<vector<array<int,2>>> adj;
array<vector<vector<int>>,2> routing_table;
vector<unordered_map<int, array<int,2>>> label_swap;
unordered_map<pair<int,int>, array<int,2>, hash_pair> fec_to_label;