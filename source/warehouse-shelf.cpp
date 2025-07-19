#include "../include/warehouse-shelf.h"
#include <stdexcept>

Shelf::Shelf() : 
    levelCapacity_(1) {}

std::string Shelf::getType() const {
    return "shelf";
}

void Shelf::setName(const std::string& name) {
    name_ = name;
}

void Shelf::setName(std::string&& name) {
    name_ = name;
}

void Shelf::addLevel(const size_t& capacity) {
    levelCapacity_.push_back(capacity);
}

void Shelf::removeLevel() {
    if (levelCapacity_.empty()) {
        throw std::logic_error("the shelf does not have any levels");
    }
    levelCapacity_.pop_back();
}

size_t Shelf::getLevelsCnt() const {
    return levelCapacity_.size();
}
