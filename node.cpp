//
// Created by Savu Liviu Gabriel on 09.03.2019.
//

#include "node.h"

void Link::setLink(Node *from, Node *to, unsigned cost) {
    this->from = from;
    this->to = to;
    this->cost = cost;
}

Node* Link::getTo() {
    return this->to;
}

Node* Link::getFrom(){
    return this->from;
}

float Link::getCost(){
    return this->cost;
}

bool operator == (const Link& link1, const Link& link2) {
    if (typeid(link1) != typeid(link2))
        return false;
    return link1.to->getName() == link2.to->getName() && link1.from->getName() == link2.from->getName() && link1.cost == link2.cost;
}

bool operator != (const Link& link1, const Link& link2) {
    return !(link1 == link2);
}

bool operator < (const Link& link1, const Link& link2) {
    return link1.cost < link2.cost;
}

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