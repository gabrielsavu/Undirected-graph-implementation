//
// Created by htpzn on 09.03.2019.
//

#ifndef GRAPH_IMPLEMENTATION_NODE_H
#define GRAPH_IMPLEMENTATION_NODE_H

#include <iostream>
#include <string>
#include <list>

class Node {
private:
    std::string name;
    std::list<unsigned> links;
public:
    void pushLink(unsigned);
    std::list<unsigned> getLinks();
    void setLinks(std::list<unsigned>);
    std::string getName();
    void setName(std::string name);
};

#endif //GRAPH_IMPLEMENTATION_NODE_H
