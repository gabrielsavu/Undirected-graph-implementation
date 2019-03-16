//
// Created by Savu Liviu Gabriel on 09.03.2019.
//

#ifndef GRAPH_IMPLEMENTATION_NODE_H
#define GRAPH_IMPLEMENTATION_NODE_H

#include <iostream>
#include <string>
#include <algorithm>
#include <list>

class Node;

class Link {
private:
    Node *from, *to;
    float cost;
public:
    Node* getTo();
    Node* getFrom();
    float getCost();
    void setLink(Node *from, Node *to, unsigned cost);
    Link(Node* from, Node* to, float cost):
        from(from), to(to), cost(cost) {}
    friend bool operator == (const Link&, const Link&);
    friend bool operator != (const Link&, const Link&);
    friend bool operator < (const Link&, const Link&);
};

class Node {
private:
    std::string name;
    unsigned position;
    std::list<Link> links;
public:
    void pushLink(Node*, float);
    std::list<Link>& getLinks();
    void setLinks(const std::list<Link>&);
    std::string getName();
    void setName(std::string);
    void setPosition(unsigned);
    unsigned getPosition();
};

#endif //GRAPH_IMPLEMENTATION_NODE_H
