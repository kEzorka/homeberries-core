#pragma once
#include "warehouse-cell.h"
#include "field.h"

class Warehouse {
public:
    Warehouse() = default;
    explicit Warehouse(const std::string& name, std::pair<int, int> fieldSize = {0,0});
    Warehouse(const Warehouse&) = default;
    Warehouse& operator=(const Warehouse&) = default;
    Warehouse(Warehouse&&) = default;
    Warehouse& operator=(Warehouse&&) = default;
    ~Warehouse() = default;

    void setName(const std::string& name);
    void setSize(std::pair<int, int> size);

    std::string getName() const;
    std::pair<int, int> getSize() const;

    WarehouseCell* operator[](std::pair<size_t, size_t> pos);
    const WarehouseCell* operator[](std::pair<size_t, size_t> pos) const;
    std::vector<WarehouseCell*> operator[](size_t row);
    const std::vector<WarehouseCell*> operator[](size_t row) const;
    WarehouseCell* at(std::pair<size_t, size_t> pos);
    const WarehouseCell* at(std::pair<size_t, size_t> pos) const;
    WarehouseCell* at(size_t row, size_t col);
    const WarehouseCell* at(size_t row, size_t col) const;

private:
    Warehouse(const Field<WarehouseCell*>& field, const std::string& name = "");
    
    std::string name_;
    Field<WarehouseCell*> field_;

};
