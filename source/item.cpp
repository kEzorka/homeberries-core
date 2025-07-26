#include "items/item.hpp"

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

void Item::removeStoringCell(VecNode& node) {
    storingCells_.erase(node);
}

std::pair<Item*, Item::VecNode>
Item::addStoringCell(WarehouseCell*const &storingCell) {
    return { this, storingCells_.push_back(storingCell) };
}
