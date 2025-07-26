#pragma once
#include <boost/date_time/gregorian/gregorian.hpp>
using namespace boost::gregorian;
#include <string>
#include <fast-vec.hpp>

#include "cell-objects/warehouse-cell.hpp"

class Item {
    using VecNode = FastVec<WarehouseCell*>::Node*;
public:
    Item() = default;
    Item(std::string name, float space, size_t accessLevel, 
        date arrivalDate = date(), date productionDate = date());
        
    void setName(std::string name);
    std::string getName() const;

    void setNeededSpace(float neededSpace);
    float getNeededSpace() const;

    void setAccesLevel(size_t accessLevel) noexcept;
    size_t getAccessLevel() const;

    void setArrivalDate(date arrivalDate);
    date getArrivalDate() const;

    void setProductionDate(date productionDate);
    date getProductionDate() const;

    std::pair<Item*, VecNode> addStoringCell(WarehouseCell*const &storingCell);
    void removeStoringCell(VecNode& node);

private:
    std::string name_;
    float neededSpace_;
    size_t accessLevel_;
    date arrivalDate_;
    date productionDate_;

    FastVec<WarehouseCell*> storingCells_;

};
