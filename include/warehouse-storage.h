#pragma once
#include <vector>
#include "fast-vec.h"
#include "warehouse-cell.h"

class Storage : public WarehouseCell {
public:
    Storage();
    Storage(const Storage&) = default;
    Storage& operator=(const Storage&) = default;
    Storage(Storage&&) = default;
    Storage& operator=(Storage&&) = default;
    ~Storage() = default;
    virtual std::string getType() const override final;
    void addLevel(const size_t& capacity = 0);
    void removeLevel();
    size_t getLevelsCnt() const;

private:
    std::vector<size_t> levelCapacity_;
    std::string name_;

};
