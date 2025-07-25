#pragma once
#include <string>

class Date {
    using uint = unsigned int;
public:
    Date() = default;
    explicit Date(uint year, uint month, uint day);
    explicit Date(uint year, const std::string& month, uint day);

private:
    uint year_;
    uint month_;
    uint day_;

    void checkDay(uint day, uint month);
    void checkMonth(uint month);
    uint monthToNum(std::string month);

};
