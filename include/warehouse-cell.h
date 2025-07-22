#pragma once
#include <string>
#include "fast-vec.h"

class Item;

class WarehouseCell {
public:
    virtual std::string getType() const = 0;
    virtual ~WarehouseCell() = default;
    
private:
    FastVec<Item*> cellItems_; 

};
