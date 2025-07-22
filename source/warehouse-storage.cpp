#include "../include/storage-shelf.h"
#include "../include/item.h"
#include <stdexcept>

Storage::Storage() : 
    levelCapacity_(1) {}

std::string Storage::getType() const {
    return "shelf";
}

void Storage::addShelf() noexcept {
    shelves_.push_back(new Shelf(1));
}

void Storage::removeShelf() {
    if (levelCapacity_.empty()) throw std::logic_error("the shelf does not have any shelves");
    delete shelves_.back();
    shelves_.pop_back();
}

size_t Storage::getShelvesCnt() const noexcept {
    return shelves_.size();
}

void Storage::setShelfItem(size_t shelfPos, Item* item) {
    checkOutOfRange(shelfPos);
    shelves_[shelfPos]->setItem(item->addStoringCell(this));
}

void Storage::removeShelfItem(size_t shelfPos) {
    checkOutOfRange(shelfPos);
    Shelf* curShelf = shelves_[shelfPos];
    curShelf->item_->removeStoringCell(curShelf->nodePtr_);
    curShelf->item_ = nullptr;
    curShelf->nodePtr_ = nullptr;
}

Storage::Shelf::Shelf(size_t level, Item* item, VecNode nodePtr) :
    level_(level), item_(item), nodePtr_(nodePtr) {};

void Storage::Shelf::setItem(std::pair<Item*, VecNode> newItem) noexcept {
    item_ = newItem.first;
    nodePtr_ = newItem.second;
}

void Storage::checkOutOfRange(size_t pos) {
    if (pos >= shelves_.size()) 
    throw std::out_of_range("shelf subscript out of range");
}
