#include <iostream>
#include <fstream>
#include <list>
#include "graph.h"



int main() {

    std::ifstream in1("graph1.in");
    std::ifstream in2("graph2.in");
    std::ofstream out1("graph1.out");
    std::ofstream out2("graph2.out");
    auto *f = new Graph();
    auto *g = new Graph();

    in1 >> *f;
    in2 >> *g;


    out2 << *g;
    g->DFS(1, out2);
    g->BFS(1, out2);
    g->connectedComponents(out2);
    g->RoyFloyd(out2);

    *f = *f + *g;
    // g is now empty.

    out1 << *f;

    f->DFS(0, out1);
    f->BFS(0, out1);
    f->connectedComponents(out1);
    f->RoyFloyd(out1);

    in1.close();
    in2.close();
    out1.close();
    out2.close();
    return 0;
}