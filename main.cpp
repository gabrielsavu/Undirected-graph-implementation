#include <iostream>
#include <fstream>
#include <list>
#include "graph.h"



int main() {

    std::ifstream in("graph1.in");
    std::ofstream out("graph1.out");
    auto *g = new Graph();
    in >> *g;
    g->DFS(0);
    std::cout << std::endl;
    g->BFS(0);
    std::cout << std::endl;
    g->connectedComponents();
    out << *g;

    return 0;
}