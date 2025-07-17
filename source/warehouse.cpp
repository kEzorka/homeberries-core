#include "../include/warehouse.h"

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
