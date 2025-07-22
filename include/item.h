#pragma once
#include "fast-vec.h"
#include "warehouse-cell.h"
#include <string>

class Item {
    using VecNode = FastVec<WarehouseCell*>::Node*;
public:
    Item() = default;
    Item(const std::string& name, float space, size_t accessLevel);
    std::string getName() const;
    float getSpace() const;
    size_t getAccessLevel() const;
    void removeStoringCell(VecNode& node);
    std::pair<Item*, VecNode> addStoringCell(WarehouseCell*const &storingCell);

private:
    std::string name_;
    float space_;
    size_t accessLevel_;

    FastVec<WarehouseCell*> storingCells_;

};
