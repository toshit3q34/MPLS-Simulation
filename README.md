# MPLS Routing Simulation in C++

This project simulates **MPLS (Multiprotocol Label Switching)** over a small 4-router network with shortest-path forwarding and label-based switching.

Implemented by :
Toshit Jain (230101106)
Tanmay Pratap Singh (230101102)
Tedla Mahaswin (230101104)
Purab Agarwal (230101083)

---

## Features Implemented
1. Link-state routing using **Dijkstra’s algorithm**  
2. MPLS **label push, swap & pop** operations  
3. FEC → Label mapping (LFIB at ingress router)  
4. Label-swap tables on intermediate routers  
5. Live forwarding trace for R0 → R3 simulation

---

## Project Structure

| File | Purpose |
|------|---------|
| `graph.h` | Routing + MPLS table structure |
| `graph.cpp` | Graph construction + Dijkstra + MPLS table builders |
| `packet.h` | Packet structure + forwarding logic |
| `packet.cpp` | Packet forwarding implementation |
| `main.cpp` | Driver: builds network and runs simulation |
| `Makefile` | Compile + run commands |

---

## Build & Run

### **Using Makefile**
```sh
make
./main
```

### **Clean build artifacts**
```sh
make clean
```