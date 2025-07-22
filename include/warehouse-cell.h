#pragma once
#include <string>

class Item;

class WarehouseCell {
public:
    virtual void addItem(Item*&) = 0;
    virtual void removeItem(Item*&) = 0;
    virtual std::string getType() const = 0;
    virtual ~WarehouseCell() = default;
    
private:

};
