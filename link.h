/*
 * Created by Savu Liviu Gabriel on 01.03.2019.
 * Compiled by mingw w64v6.0.0: 2018-09-17 C++17 standard.
 */

#ifndef GRAPH_IMPLEMENTATION_LINK_H
#define GRAPH_IMPLEMENTATION_LINK_H

#include "node.h"
#include <typeinfo>
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
