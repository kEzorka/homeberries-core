#pragma once
#include <vector>
#include "warehouse-cell.h"

class Shelf : public WarehouseCell {
public:
    Shelf();
    Shelf(const Shelf&) = default;
    Shelf& operator=(const Shelf&) = default;
    Shelf(Shelf&&) = default;
    Shelf& operator=(Shelf&&) = default;
    ~Shelf() = default;
    virtual std::string getType() const override final;
    void addLevel(const size_t& capacity = 0);
    void removeLevel();
    size_t getLevelsCnt() const;

private:
    std::vector<size_t> levelCapacity_;
    std::string name_;

};
