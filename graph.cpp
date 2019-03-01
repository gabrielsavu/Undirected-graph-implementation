//
// Created by Savu Liviu Gabriel on 01.03.2019.
//
#include "graph.h"

void Node::pushLink(unsigned v) {
    this->links.push_back(v);
}

std::list<unsigned> Node::getLinks() {
    return this->links;
}

void Graph::allocMemory(unsigned size) {
    this->nodes = new Node[size];
}

void Graph::addLink(unsigned v, unsigned u) {
    if (v >= this->number_of_nodes || u >= this->number_of_nodes) {
        return;
    }
    this->nodes[v].pushLink(u);
    this->nodes[u].pushLink(v);
}

std::ostream &operator << (std::ostream& output, const Graph& G) {
    unsigned i;
    for(i = 0; i < G.number_of_nodes; i ++) {
        output << i << std::endl;
        for(auto it : G.nodes[i].getLinks()) {
            output << it << " ";
        }
        output << std::endl << "------------" << std::endl;
    }
    return output;
}
std::istream& operator >> (std::istream& input, Graph& G) {
    input >> G.number_of_nodes;
    G.allocMemory(G.number_of_nodes);
    unsigned v, w;
    input >> G.number_of_links;
    for (unsigned i = 0; i < G.number_of_links; i ++) {
        input >> v >> w;
        G.addLink(v, w);
    }
    return input;
}

Graph::Graph(unsigned nodes) {
    this->number_of_nodes = nodes;
    this->number_of_links = 0;
    allocMemory(this->number_of_nodes);
}

Graph::Graph(): number_of_nodes(0), number_of_links(0), nodes(nullptr) {}