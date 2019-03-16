//
// Created by Savu Liviu Gabriel on 09.03.2019.
//

#include "node.h"

void Node::pushLink(Node *v, float cost) {
    Link l(this, v, cost);
    auto it = std::find(this->links.begin(), this->links.end(), l);

    if(it == this->links.end())
        this->links.push_back(l);
}

void Node::setPosition(unsigned position) {
    this->position = position;
}

unsigned Node::getPosition() {
    return this->position;
}

std::list<Link>& Node::getLinks() {
    return this->links;
}

void Node::setLinks(const std::list<Link>& l){
    this->links = l;
}

std::string Node::getName(){
    return this->name;
}

void Node::setName(std::string name){
    this->name = name;
}