#include "packet.h"
#include "graph.h"

int main()
{
    FILE* file = fopen("output.txt","w");
    // Building the graph of network
    buildGraph();
    for (int i = 0; i < NODES; i++)
    {
        // Building routing tables
        djikstraPerNode(i);
    }
    // Building LFIB(s)
    buildFECtoLabel(R0,R3);
    buildLabelSwap(R0,R3);

    // Printing routing tables
    printRoutingTables(file);

    // Simulation henceforth
    Packet packet = {R0,R3,EMPTY_LABEL};
    int router = R0;
    // Simulation in a while loop (returns 0 when received)
    while(forwardPacket(router,packet,file));
}