#pragma once
#include <string>

class Item {
public:
    Item() = default;
    Item(const std::string& name, float space, size_t accessLevel);
    std::string getName() const;
    float getSpace() const;
    size_t getAccessLevel() const;

private:
    std::string name_;
    float space_;
    size_t accessLevel_;

};
