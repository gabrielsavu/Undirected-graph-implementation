//
// Created by Savu Liviu Gabriel on 01.03.2019.
//

#ifndef GRAPH_IMPLEMENTATION_LINK_H
#define GRAPH_IMPLEMENTATION_LINK_H

#include "node.h"
class Node;

class Link {
private:
    Node *from, *to;
    float cost;
public:
    Node *getTo();

    Node *getFrom();

    float getCost();

    void setLink(Node *from, Node *to, unsigned cost);

    Link(Node *from, Node *to, float cost) :
            from(from), to(to), cost(cost) {}

    friend bool operator==(const Link &, const Link &);

    friend bool operator!=(const Link &, const Link &);

    friend bool operator<(const Link &, const Link &);
};
#endif //GRAPH_IMPLEMENTATION_LINK_H
