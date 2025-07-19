#pragma once
#include <string>

class WarehouseCell {
public:
    virtual std::string getType() const = 0;
    virtual ~WarehouseCell() = default;
    
private:

};
