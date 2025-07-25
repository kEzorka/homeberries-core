#include <date.hpp>
#include <initializer_list>
#include <algorithm>
#include <stdexcept>
#include <cctype>
#include <boost/locale.hpp>

template<typename T, typename Ts>
bool is_in(const T& v, const std::initializer_list<Ts>& list) {
    return std::find(list.begin(), list.end(), v) != list.end();
}

std::string toLower(std::string str) {
    std::locale loc("ru_RU.UTF-8");
    std::transform(
        str.begin(), str.end(), str.begin(),
     [&loc](unsigned char c){
        return std::tolower(c, loc);
    });
    return str;
}

Date::Date(uint year, uint month, uint day) : 
    year_(year) 
{

}

void Date::checkDay(uint day, uint month) {
    checkMonth(month);
    if (is_in(month, {1, 3, 5, 7, 8, 10, 12})) {
        if (day > 31) 
        throw std::invalid_argument("in month number " + std::to_string(month) + " have to be no more than 31 day");
    } else if (is_in(month, {4, 6, 9, 11})) {
        if (day > 30) 
        throw std::invalid_argument("in month number " + std::to_string(month) + " have to be no more than 30 day");
    } else {
        if (day > 28)
        throw std::invalid_argument("in month number " + std::to_string(month) + " have to be no more than 28 day");
    }
}

void Date::checkMonth(uint month) {
    if (month > 12)
    throw std::invalid_argument("month number have to be no more than 12");
}

uint Date::monthToNum(std::string month) {
    return uint();
}
