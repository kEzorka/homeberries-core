#pragma once
#include <vector>
#include "warehouse-cell.h"

class Storage : public WarehouseCell {
public:
    class Shelf;
public:
    Storage();
    Storage(const Storage&) = default;
    Storage& operator=(const Storage&) = default;
    Storage(Storage&&) = default;
    Storage& operator=(Storage&&) = default;
    ~Storage() = default;
    virtual std::string getType() const override final;
    void addShelf() noexcept;
    void removeShelf();
    size_t getShelvesCnt() const noexcept;
    void setShelfItem(size_t shelfPos, Item* item);
    void removeShelfItem(size_t shelfPos);

private:
    std::vector<Shelf*> shelves_;
    std::string name_;
    
    /**
        *@brief Shelf capacity is increasing by the level
    */
    std::vector<size_t> levelCapacity_ = { 0, 10, 25, 40 };
    void checkOutOfRange(size_t pos);
    
};
