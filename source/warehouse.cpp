#include "../include/warehouse.h"
#include <utility>

Warehouse::Warehouse(const std::string& name, std::pair<size_t, size_t> size) :
    name_(name), field_(Field(size)) {}

Warehouse::Warehouse(const Field& field, const std::string& name) : 
    name_(name), field_(field) {}


void Warehouse::setName(const std::string& name) {
    name_ = name;
}
void Warehouse::setSize(std::pair<size_t, size_t> size) {
    field_.resize(size);
}


std::string Warehouse::getName() const {
    return name_;
}
std::pair<int, int> Warehouse::getSize() const {
    return field_.size();
}


Warehouse::Cell Warehouse::operator[](std::pair<size_t, size_t> pos) {
    return field_[pos];
}
const Warehouse::Cell Warehouse::operator[](std::pair<size_t, size_t> pos) const {
    return field_[pos];
}

Warehouse::Field::Row Warehouse::operator[](size_t row) {
    return field_[row];
}
const Warehouse::Field::Row Warehouse::operator[](size_t row) const {
    return field_[row];
}

Warehouse::Cell Warehouse::at(std::pair<size_t, size_t> pos) {
    return field_[pos];
}
const Warehouse::Cell Warehouse::at(std::pair<size_t, size_t> pos) const {
    return field_[pos];
}

Warehouse::Cell Warehouse::at(size_t row, size_t col) {
    return field_.at(row, col);
}
const Warehouse::Cell Warehouse::at(size_t row, size_t col) const {
    return field_.at(row, col);
}
