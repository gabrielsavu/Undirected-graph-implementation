//
// Created by htpzn on 09.03.2019.
//

#include "node.h"

void Node::pushLink(unsigned v) {
    this->links.push_back(v);
}

std::list<unsigned> Node::getLinks() {
    return this->links;
}

void Node::setLinks(std::list<unsigned> l){
    this->links = l;
}

std::string Node::getName(){
    return this->name;
}

void Node::setName(std::string name){
    this->name = name;
}