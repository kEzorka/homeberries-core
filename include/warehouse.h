#pragma once
#include "warehouse-cell.h"
#include "matrix.h"
#include <memory>

class Warehouse {
private:
    using Cell = std::shared_ptr<WarehouseCell>;
    using Field = Matrix<Cell>;

public:
    Warehouse() = default;
    explicit Warehouse(const std::string& name, std::pair<int, int> fieldSize = {0,0});

    void setName(const std::string& name);
    void setSize(std::pair<int, int> size);

    std::string getName() const;
    std::pair<int, int> getSize() const;

    Cell operator[](std::pair<size_t, size_t> pos);
    const Cell operator[](std::pair<size_t, size_t> pos) const;
    Field::Row operator[](size_t row);
    const Field::Row operator[](size_t row) const;
    Cell at(std::pair<size_t, size_t> pos);
    const Cell at(std::pair<size_t, size_t> pos) const;
    Cell at(size_t row, size_t col);
    const Cell at(size_t row, size_t col) const;

private:
    Warehouse(const Field& field, const std::string& name = "");
    
    std::string name_;
    Field field_;

};
