#include "../include/warehouse.h"
#include <utility>

Warehouse::Warehouse(const std::string& name, std::pair<int, int> size) :
    name_(name), field_(Field<WarehouseCell*>(size)) {}

Warehouse::Warehouse(const Field<WarehouseCell*>& field, const std::string& name) : 
    name_(name), field_(field) {}


void Warehouse::setName(const std::string& name) {
    name_ = name;
}
void Warehouse::setSize(std::pair<int, int> size) {
    field_.resize(size);
}


std::string Warehouse::getName() const {
    return name_;
}
std::pair<int, int> Warehouse::getSize() const {
    return field_.size();
}


WarehouseCell* Warehouse::operator[](std::pair<size_t, size_t> pos) {
    return field_[pos];
}
const WarehouseCell* Warehouse::operator[](std::pair<size_t, size_t> pos) const {
    return field_[pos];
}

std::vector<WarehouseCell*> Warehouse::operator[](size_t row) {
    return field_[row];
}
const std::vector<WarehouseCell*> Warehouse::operator[](size_t row) const {
    return field_[row];
}

WarehouseCell* Warehouse::at(std::pair<size_t, size_t> pos) {
    return field_[pos];
}
const WarehouseCell* Warehouse::at(std::pair<size_t, size_t> pos) const {
    return field_[pos];
}

WarehouseCell* Warehouse::at(size_t row, size_t col) {
    return field_.at(row, col);
}
const WarehouseCell* Warehouse::at(size_t row, size_t col) const {
    return field_.at(row, col);
}
