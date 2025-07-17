#pragma once
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
