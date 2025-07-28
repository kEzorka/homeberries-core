#pragma once
#include <stdexcept>
#include <vector>

template<typename T>
class Matrix {
public:
    using Row = std::vector<T>;
    using Field = std::vector<Row>;

public:
    Matrix() = default;
    explicit Matrix(std::pair<size_t, size_t> size) noexcept :
        field_(Field(size.first, Row(size.second))) {}

    void resize(std::pair<size_t, size_t> size);

    std::pair<size_t, size_t> size() const;

    Matrix(const Matrix&) = default;
    Matrix& operator=(const Matrix&) = default;
    Matrix(Matrix&&) noexcept = default;
    Matrix& operator=(Matrix&&) noexcept = default;
    ~Matrix() = default;

    T& operator[](std::pair<size_t, size_t> pos);
    const T& operator[](std::pair<size_t, size_t> pos) const;
    Row& operator[](size_t row);
    const Row& operator[](size_t row) const;
    T& at(std::pair<size_t, size_t> pos);
    const T& at(std::pair<size_t, size_t> pos) const;
    T& at(size_t row, size_t col);
    const T& at(size_t row, size_t col) const;

private:
    void checkBounds(size_t row) const;
    void checkBounds(std::pair<size_t, size_t> pos) const;

    Field field_;

};

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
    if (row >= field_.size())
        throw std::out_of_range("position out of field");
}
template<typename T>
void Matrix<T>::checkBounds(std::pair<size_t, size_t> pos) const {
    if (pos.first >= field_.size() || pos.second >= field_[0].size())
        throw std::out_of_range("position out of field");
}
