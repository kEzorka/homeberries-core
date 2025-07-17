#include "../include/matrix.h"
#include <stdexcept>

template<typename T>
void Matrix<T>::resize(std::pair<size_t, size_t> size) {
    field_.resize(size.first, std::vector<T>(size.second));
}

template<typename T>
std::pair<size_t, size_t> Matrix<T>::size() const {
    if (field_.empty()) return {0, 0};
    return {field_.size(), field_[0].size()};
}


template<typename T>
T& Matrix<T>::operator[](std::pair<size_t, size_t> pos) {
    checkBounds(pos);
    return field_[pos.first][pos.second];
}
template<typename T>
const T& Matrix<T>::operator[](std::pair<size_t, size_t> pos) const {
    return at(pos);
}


template<typename T>
Matrix<T>::Row& Matrix<T>::operator[](size_t row) {
    checkBounds(row);
    return field_[row];
}
template<typename T>
const Matrix<T>::Row& Matrix<T>::operator[](size_t row) const {
    checkBounds(row);
    return field_[row];
}


template<typename T>
T& Matrix<T>::at(std::pair<size_t, size_t> pos) {
    checkBounds(pos);
    return field_[pos.first][pos.second];
}
template<typename T>
const T& Matrix<T>::at(std::pair<size_t, size_t> pos) const {
    checkBounds(pos);
    return field_[pos.first][pos.second];
}


template<typename T>
T& Matrix<T>::at(size_t row, size_t col) {
    checkBounds({ row, col });
    return at({ row, col });
}
template<typename T>
const T& Matrix<T>::at(size_t row, size_t col) const {
    checkBounds({ row, col });
    return at({ row, col });
}


template<typename T>
void Matrix<T>::checkBounds(size_t row) const {
    if (row >= field_.size()) {
        throw std::out_of_range("position out of field");
    }
}
template<typename T>
void Matrix<T>::checkBounds(std::pair<size_t, size_t> pos) const {
    if (pos.first >= field_.size() || pos.second >= field_[0].size()) {
        throw std::out_of_range("position out of field");
    }
}
