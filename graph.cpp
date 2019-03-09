//
// Created by Savu Liviu Gabriel on 01.03.2019.
//
#include "graph.h"

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

std::ostream& operator << (std::ostream& output, const Graph& G) {
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

Graph::~Graph() {
    this->number_of_nodes = 0;
    this->number_of_links = 0;
    delete[] nodes;
}

Graph::Graph(const Graph& G) {
    this->number_of_links = G.number_of_links;
    this->number_of_nodes = G.number_of_nodes;
    this->nodes = G.nodes;
}

Graph& Graph::operator=(const Graph& G) {
    if (this != &G) {
        Node* new_nodes = new Node[G.number_of_nodes];
        std::copy(G.nodes, G.nodes + G.number_of_nodes, new_nodes);
        //delete[] nodes;
        nodes = new_nodes;
        this->number_of_links = G.number_of_links;
        this->number_of_nodes = G.number_of_nodes;
    }
    return *this;
}

bool Graph::operator < (const Graph& G) {
    return this->number_of_nodes < G.number_of_nodes;
}

bool Graph::operator == (const Graph& G) {
    if (this->number_of_nodes == G.number_of_nodes && this->number_of_links == G.number_of_links) {
        unsigned i;
        for (i = 0; i < this->number_of_nodes; i ++) {
            if (this->nodes[i].getLinks() != G.nodes[i].getLinks())
                return false;
        }
        return true;
    }
    return false;
}

bool Graph::operator != (const Graph& G) {
    return !(*this == G);
}

Graph Graph::operator+(const Graph& G) {
    Graph graph;
    unsigned i;
    if (G.number_of_nodes > this->number_of_nodes) {
        graph = G;
        for(i = 0; i < this->number_of_nodes; i ++) {
            graph.nodes[i].getLinks().merge(this->nodes[i].getLinks());
            graph.nodes[i].getLinks().unique();
        }
    }
    else {
        graph = *this;
        for(i = 0; i < G.number_of_nodes; i ++) {
            graph.nodes[i].getLinks().merge(G.nodes[i].getLinks());
            graph.nodes[i].getLinks().unique();
        }
    }

    return graph;
}

void Graph::DFSUtil(unsigned node, bool visited[]) {
    std::stack<unsigned> s;
    s.push(node);
    while (!s.empty()) {
        auto v = s.top();
        s.pop();
        if (!visited[v]) {
            std::cout << v << " ";
            visited[v] = true;
            for(auto it : this->nodes[v].getLinks())
                s.push(it);
        }
    }
}

void Graph::BFSUtil(unsigned node, bool visited[]) {
    std::queue<unsigned> q;
    q.push(node);
    while (!q.empty()) {
        if (!visited[q.front()]) {
            std::cout << q.front() << " ";
            visited[q.front()] = true;
            for(auto it : this->nodes[q.front()].getLinks())
                if(!visited[it]) q.push(it);
        }
        q.pop();
    }
}

void Graph::DFS(unsigned start) {
    bool *visited = new bool[this->number_of_nodes];
    for (unsigned i = 0; i < this->number_of_nodes; i++)
        visited[i] = false;

    DFSUtil(start, visited);
}

void Graph::BFS(unsigned start) {
    bool *visited = new bool[this->number_of_nodes];
    for (unsigned i = 0; i < this->number_of_nodes; i++)
        visited[i] = false;

    BFSUtil(start, visited);
}

void Graph::connectedComponents() {
    bool *visited = new bool[this->number_of_nodes];
    for(unsigned i = 0; i < this->number_of_nodes; i++)
        visited[i] = false;

    for (unsigned i = 0; i < this->number_of_nodes; i++) {
        if (!visited[i]) {
            DFSUtil(i, visited);
            std::cout << "\n";
        }
    }
}
