//
// Created by Savu Liviu Gabriel on 01.03.2019.
//

#ifndef GRAPH_CLASS_GRAPH_H
#define GRAPH_CLASS_GRAPH_H

#include <iostream>
#include <queue>
#include <list>

class Node {
private:
    std::list<unsigned> links;
public:
    void pushLink(unsigned);
    std::list<unsigned> getLinks();
    void setLinks(std::list<unsigned>);
};


class Graph {
private:
    unsigned number_of_nodes;
    unsigned number_of_links;
    Node *nodes;
public:
    Graph();
    ~Graph();
    explicit Graph(unsigned);
    Graph(const Graph&);
    void allocMemory(unsigned);
    void addLink(unsigned, unsigned);
    void DFSUtil(unsigned, bool[]);
    void DFS(unsigned);
    void connectedComponents();
    friend std::ostream& operator << (std::ostream&, const Graph&);
    friend std::istream& operator >> (std::istream&, Graph&);
    bool operator == (const Graph&);
    bool operator != (const Graph&);
    bool operator < (const Graph&);
    Graph& operator = (const Graph&);
    Graph operator + (const Graph&);
};


#endif //GRAPH_CLASS_GRAPH_H
