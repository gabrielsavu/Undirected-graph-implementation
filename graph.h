//
// Created by Savu Liviu Gabriel on 01.03.2019.
//

#ifndef GRAPH_CLASS_GRAPH_H
#define GRAPH_CLASS_GRAPH_H

#include <iostream>
#include <list>

class Node {
private:
    std::list<unsigned> links;
public:
    void pushLink(unsigned);
    std::list<unsigned> getLinks();
};


class Graph {
private:
    unsigned number_of_nodes;
    unsigned number_of_links;
    Node *nodes;
public:
    Graph();
    explicit Graph(unsigned);
    void allocMemory(unsigned);
    void addLink(unsigned, unsigned);
    friend std::ostream &operator << (std::ostream&, const Graph&);
    friend std::istream& operator >> (std::istream&, Graph&);
};


#endif //GRAPH_CLASS_GRAPH_H
