#include "items/item.hpp"
#include <boost/date_time/date_facet.hpp>
#include <stdexcept>

Item::Item(std::string name, float neededSpace, size_t accessLevel, 
    date arrivalDate, date productionDate) :
    name_(std::move(name)), neededSpace_(std::move(neededSpace)), accessLevel_(std::move(accessLevel)),
    arrivalDate_(std::move(arrivalDate)), 
    productionDate_(productionDate.is_not_a_date() ? arrivalDate_ : std::move(productionDate)) {}


void Item::setName(std::string name) {
    name_ = std::move(name);
}
std::string Item::getName() const {
    return name_;
}


void Item::setNeededSpace(float neededSpace) {
    if (neededSpace < 0)
        throw std::invalid_argument("needed space cannot be negative");
    neededSpace_ = std::move(neededSpace);
}
float Item::getNeededSpace() const {
    return neededSpace_;
}


void Item::setAccesLevel(size_t accessLevel) noexcept {
    accessLevel_ = std::move(accessLevel);
}
size_t Item::getAccessLevel() const {
    return accessLevel_;
}


void Item::setArrivalDate(date arrivalDate) {
    arrivalDate_ = std::move(arrivalDate);
}
date Item::getArrivalDate() const {
    return arrivalDate_;
}


void Item::setProductionDate(date productionDate) {
    if (productionDate > arrivalDate_)
        throw std::invalid_argument("production date cannot exceed arrival date");
    productionDate_ = std::move(productionDate);
}
date Item::getProductionDate() const {
    return productionDate_;
}


std::pair<Item*, Item::VecNode>
Item::addStoringCell(WarehouseCell*const &storingCell) {
    return { this, storingCells_.push_back(storingCell) };
}
void Item::removeStoringCell(VecNode& node) {
    storingCells_.erase(node);
}
