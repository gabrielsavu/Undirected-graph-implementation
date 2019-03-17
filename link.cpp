/*
 * Created by Savu Liviu Gabriel on 01.03.2019.
 * Compiled by mingw w64v6.0.0: 2018-09-17 C++17 standard.
 */

#include "link.h"

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
