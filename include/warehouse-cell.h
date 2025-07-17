#pragma once
#include <string>
class WarehouseCell {
public:
    virtual void setType(const std::string& type) = 0;
    virtual void setType(std::string&& type) = 0;
    virtual std::string getType() const = 0;

    virtual ~WarehouseCell() = default;
    
private:

};
