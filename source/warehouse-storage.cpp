#include "../include/warehouse-storage.h"
#include <stdexcept>

Storage::Storage() : 
    levelCapacity_(1) {}

std::string Storage::getType() const {
    return "shelf";
}

void Storage::addLevel(const size_t& capacity) {
    levelCapacity_.push_back(capacity);
}

void Storage::removeLevel() {
    if (levelCapacity_.empty()) {
        throw std::logic_error("the shelf does not have any levels");
    }
    levelCapacity_.pop_back();
}

size_t Storage::getLevelsCnt() const {
    return levelCapacity_.size();
}
