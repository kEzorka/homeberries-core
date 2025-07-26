#pragma once
#include <fast-vec.hpp>

#include "warehouse-storage.hpp"

class Storage::Shelf {
    using VecNode = FastVec<WarehouseCell*>::Node*;
    friend class Storage;
public:
    Shelf() = default;
    explicit Shelf(size_t level, Item* item = nullptr, VecNode nodePtr = nullptr);
    void setItem(std::pair<Item*, VecNode> newItem) noexcept;
    ~Shelf() = default;

private:
    size_t level_ = 0;
    Item* item_ = nullptr;
    VecNode nodePtr_ = nullptr;
    
};
