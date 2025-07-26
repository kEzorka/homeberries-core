#pragma once
#include "item.hpp"

class Product : public Item {
public:

private:
    /// @brief count of days
    gregorian::date_duration expirationDate;
    
};
