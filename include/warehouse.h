#pragma once
#include <string>

#include "warehouse-cell.h"
#include "field.h"

class Warehouse {
public:
    explicit Warehouse() = default;
    explicit Warehouse(const std::string& name, std::pair<int, int> fieldSize = {0,0});

    void setName(const std::string& name);
    void setSize(std::pair<int, int> size);

    std::string getName() const;
    std::pair<int, int> getSize() const;

private:
    Warehouse(const Field<WarehouseCell*>& field);
    
    std::string name_;
    Field<WarehouseCell*> field_;

};
