/*
 * Created by Savu Liviu Gabriel on 01.03.2019.
 * Compiled by mingw w64v6.0.0: 2018-09-17 C++17 standard.
 */

#include "graph.h"


Graph::Graph(unsigned nodes) {
    this->number_of_nodes = nodes;
    this->number_of_links = 0;
    allocMemory(this->number_of_nodes);
}

Graph::Graph(): number_of_nodes(0), number_of_links(0), nodes(nullptr) {}

Graph::~Graph() {
    this->number_of_nodes = 0;
    this->number_of_links = 0;
    delete[] this->nodes;
}

void Graph::allocMemory(unsigned size) {
    this->nodes = new Node[size];
    for(unsigned i = 0; i < size; i ++) {
        this->nodes[i].setPosition(i);
    }
}

void Graph::freeMemory() {
    delete[] this->nodes;
}

void Graph::addLink(Node *v, Node *u, float cost = 0) {
    v->pushLink(u, cost);
    u->pushLink(v, cost);
}

Graph::Graph(const Graph& G) {
    unsigned i;
    delete[] this->nodes;
    allocMemory(G.number_of_nodes);
    for (i = 0; i < G.number_of_nodes; i ++) {
        this->nodes[i].setName(G.nodes[i].getName());
        for(auto it : G.nodes[i].getLinks()) {
            this->addLink(this->nodes + this->nodes[i].getPosition(), this->nodes + it.getTo()->getPosition(), it.getCost());
        }
    }
    this->number_of_links = G.number_of_links;
    this->number_of_nodes = G.number_of_nodes;
}

std::ostream& operator << (std::ostream& output, const Graph& G) {
    unsigned i;
    for(i = 0; i < G.number_of_nodes; i ++) {
        output << "Position in memory: " << G.nodes + i << std::endl;
        output << "Name: " << G.nodes[i].getName() << std::endl;
        output << "Adjacency list: " ;
        for(auto it : G.nodes[i].getLinks()) {
            output << "(" << it.getTo() << "," << it.getTo()->getName() << ") ";
        }
        output << std::endl << "------------" << std::endl;
    }
    return output;
}

std::istream& operator >> (std::istream& input, Graph& G) {
    input >> G.number_of_nodes;
    if (G.number_of_nodes <= 0) return input;
    G.allocMemory(G.number_of_nodes);
    unsigned v, w, cost;
    input >> G.number_of_links;
    if (G.number_of_links <= 0) {
        G.freeMemory();
        return input;
    }
    for (unsigned i = 0; i < G.number_of_links; i ++) {
        input >> v >> w >> cost;
        G.nodes[v].setName(std::to_string(v));
        G.nodes[w].setName(std::to_string(w));
        G.addLink(&G.nodes[v], &G.nodes[w], cost);
    }
    return input;
}

Graph& Graph::operator = (const Graph& G) {
    if (this != &G) {
        unsigned i;
        delete[] this->nodes;
        allocMemory(G.number_of_nodes);
        for (i = 0; i < G.number_of_nodes; i ++) {
            this->nodes[i].setName(G.nodes[i].getName());
            for(auto it : G.nodes[i].getLinks()) {
                this->addLink(this->nodes + this->nodes[i].getPosition(), this->nodes + it.getTo()->getPosition(), it.getCost());
            }
        }
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

Graph Graph::operator + (const Graph& G) {
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

void Graph::DFSUtil(unsigned node, bool visited[], std::list<Node*>& out) {
    std::stack<Node*> s;
    s.push(this->nodes + node);
    while (!s.empty()) {
        auto v = s.top();
        s.pop();
        if (!visited[v->getPosition()]) {
            out.push_back(v);
            visited[v->getPosition()] = true;
            for(auto it : v->getLinks())
                s.push(it.getTo());
        }
    }
}

void Graph::BFSUtil(unsigned node, bool visited[], std::list<Node*>& out) {
    std::queue<Node*> q;
    q.push(this->nodes + node);
    while (!q.empty()) {
        auto v = q.front();
        if (!visited[v->getPosition()]) {
            out.push_back(v);
            visited[v->getPosition()] = true;
            for(auto it : v->getLinks())
                q.push(it.getTo());
        }
        q.pop();
    }
}

void Graph::DFS(unsigned start, std::ostream& out) {
    if (start >= this->number_of_nodes)
        return;
    try {
        bool *visited = new bool[this->number_of_nodes];
        std::list<Node*> list;
        for (unsigned i = 0; i < this->number_of_nodes; i++)
            visited[i] = false;

        DFSUtil(start, visited, list);
        out << "DFS from node (" << this->nodes + start << "," << this->nodes[start].getName() <<"): ";
        for(auto&& it : list) {
            out << "(" << it << "," << it->getName() << ") ";
        }
        out << std::endl;
    }
    catch (std::exception& e) {
        out << "Exception catch: " << e.what() << std::endl;
    }

}

void Graph::BFS(unsigned start, std::ostream& out) {
    if (start >= this->number_of_nodes)
        return;
    try {
        bool *visited = new bool[this->number_of_nodes];
        std::list<Node*> list;
        for (unsigned i = 0; i < this->number_of_nodes; i++)
            visited[i] = false;

        BFSUtil(start, visited, list);
        out << "BFS from node (" << this->nodes + start << "," << this->nodes[start].getName() <<"): ";
        for(auto&& it : list) {
            out << "(" << it << "," << it->getName() << ") ";
        }
        out << std::endl;
    }
    catch (std::exception& e) {
        out << "Exception catch: " << e.what() << std::endl;
    }
}

void Graph::connectedComponents(std::ostream& out) {
    try {
        bool *visited = new bool[this->number_of_nodes];
        std::list<Node*> list;
        for(unsigned i = 0; i < this->number_of_nodes; i++)
            visited[i] = false;

        for (unsigned i = 0; i < this->number_of_nodes; i++) {
            if (!visited[i]) {
                DFSUtil(i, visited, list);
                out << "Connected component: ";
                for(auto&& it : list) {
                    out << "(" << it << "," << it->getName() << ") ";
                }
                list.clear();
                out << std::endl;
            }
        }
    }
    catch (std::exception& e) {
        std::cout << "Exception catch: " << e.what() << std::endl;
    }
}

bool Graph::isConnectedComponents() {
    unsigned c = 0;
    try {
        bool *visited = new bool[this->number_of_nodes];
        std::list<Node*> list;
        for(unsigned i = 0; i < this->number_of_nodes; i++)
            visited[i] = false;

        for (unsigned i = 0; i < this->number_of_nodes; i++) {
            if (!visited[i]) {
                DFSUtil(i, visited, list);
                list.clear();
                c ++;
            }
        }
    }
    catch (std::exception& e) {
        std::cout << "Exception catch: " << e.what() << std::endl;
    }
    return c <= 1;
}


void Graph::RoyFloyd(std::ostream& out) {
    unsigned **a, i, j, k;
    a = new unsigned*[this->number_of_nodes];
    for (i = 0; i < this->number_of_nodes; i ++)
        a[i] = new unsigned[this->number_of_nodes];

    for (i = 0; i < this->number_of_nodes; i ++)
        for (j = 0; j < this->number_of_nodes; j ++)
            if (i == j) a[i][j] = 0;
            else a[i][j] = UINT_MAX;


    for (i = 0; i < this->number_of_nodes; i ++)
        for(auto it : this->nodes[i].getLinks())
            a[i][it.getTo()->getPosition()] = a[it.getTo()->getPosition()][i] = (unsigned)it.getCost();

    for (k = 0; k < this->number_of_nodes; k ++)
        for (i = 0; i < this->number_of_nodes; i ++)
            for (j = 0; j < this->number_of_nodes; j ++)
                if (a[i][j] > a[i][k] + a[k][j])
                    a[i][j] = a[i][k] + a[k][j];

    out << "Roy-Floyd:" << std::endl;
    for (i = 0; i < this->number_of_nodes; i ++) {
        for (j = 0; j < this->number_of_nodes; j++)
            out << a[i][j] << " ";
        out << std::endl;
    }
    for (i = 0; i < this->number_of_nodes; i ++)
        delete a[i];
    delete[] a;
}
