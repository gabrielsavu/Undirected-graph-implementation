//
// Created by Savu Liviu Gabriel on 09.03.2019.
//

#ifndef GRAPH_IMPLEMENTATION_NODE_H
#define GRAPH_IMPLEMENTATION_NODE_H

#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include "link.h"

class Link;

class Node {
private:
    std::string name;
    unsigned position;
    std::list<Link> links;
public:
    void pushLink(Node *, float);

    std::list<Link> &getLinks();

    void setLinks(const std::list<Link> &);

    std::string getName();

    void setName(std::string);

    void setPosition(unsigned);

    unsigned getPosition();
};

#endif //GRAPH_IMPLEMENTATION_NODE_H
