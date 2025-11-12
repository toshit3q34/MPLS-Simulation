#include "packet.h"
#include "graph.h"

int forwardPacket(int& router, Packet& packet, FILE* file){
    if (packet.label == EMPTY_LABEL){
        auto [new_label, next_hop] = fec_to_label[{packet.source,packet.destination}];
        fprintf(file,"[R%d] Packet for R%d (FEC R%d->R%d). Pushing Label %d. Sending to R%d\n",
                    router, packet.destination, router, packet.destination, new_label, next_hop);
        packet.label = new_label;
        router = next_hop;
        return 1;
    }
    else{
        if(packet.destination == router){
            fprintf(file,"[R%d] Received packet with In-Label %d. Popping Label. Packet delivered.\n",
                    router, packet.label);
            packet.label = EMPTY_LABEL;
            return 0;
        }
        else{
            auto [new_label, next_hop] = label_swap[router][packet.label];
            fprintf(file,"[R%d] Received packet with In-Label %d. Swapping for Out-Label %d. Sending to R%d.\n",
                    router, packet.label, new_label, next_hop);
            packet.label = new_label;
            router = next_hop;
            return 1;
        }
    }
}