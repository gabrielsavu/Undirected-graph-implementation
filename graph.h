//
// Created by Savu Liviu Gabriel on 01.03.2019.
//

#ifndef GRAPH_CLASS_GRAPH_H
#define GRAPH_CLASS_GRAPH_H

#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <exception>
#include <bits/stdc++.h>
#include "link.h"
#include "node.h"

class Link;

class Graph {
private:
    unsigned number_of_nodes;
    unsigned number_of_links;
    Node *nodes;
public:
    Graph();

    ~Graph();

    explicit Graph(unsigned);

    Graph(const Graph &);

    void allocMemory(unsigned);

    void freeMemory();

    void addLink(Node *, Node *, float);

    void BFSUtil(unsigned, bool[], std::list<Node *> &);

    void DFSUtil(unsigned, bool[], std::list<Node *> &);

    void DFS(unsigned start, std::ostream &);

    void BFS(unsigned start, std::ostream &);

    void connectedComponents(std::ostream &out);

    bool isConnectedComponents();

    void RoyFloyd(std::ostream &);

    friend std::ostream &operator<<(std::ostream &, const Graph &);

    friend std::istream &operator>>(std::istream &, Graph &);

    bool operator==(const Graph &);

    bool operator!=(const Graph &);

    bool operator<(const Graph &);

    Graph &operator=(const Graph &);

    Graph operator+(const Graph &);
};

#endif //GRAPH_CLASS_GRAPH_H
