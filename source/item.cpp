#include "../include/item.h"

Item::Item(const std::string& name, float space, size_t accessLevel) :
    name_(name), space_(space), accessLevel_(accessLevel) {}

std::string Item::getName() const {
    return name_;
}

float Item::getSpace() const {
    return space_;
}

size_t Item::getAccessLevel() const {
    return accessLevel_;
}
