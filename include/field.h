#pragma once
#include <vector>

template<typename T>
class Field {
public:
    using Matrix = std::vector<std::vector<T>>;

public:
    Field() = default;
    explicit Field(std::pair<int, int> size) noexcept :
        field_(Matrix(size.first, std::vector<T>(size.second))) {}

    void resize(std::pair<int, int> size);

    std::pair<int, int> size() const;

    Field(const Field&) = default;
    Field& operator=(const Field&) = default;
    Field(Field&&) noexcept = default;
    Field& operator=(Field&&) noexcept = default;
    ~Field() = default;

    T& operator[](std::pair<size_t, size_t> pos);
    const T& operator[](std::pair<size_t, size_t> pos) const;
    std::vector<T>& operator[](size_t row);
    const std::vector<T>& operator[](size_t row) const;
    T& at(std::pair<size_t, size_t> pos);
    const T& at(std::pair<size_t, size_t> pos) const;
    T& at(size_t row, size_t col);
    const T& at(size_t row, size_t col) const;

private:
    void checkBounds(size_t row) const;
    void checkBounds(std::pair<size_t, size_t> pos) const;

    Matrix field_;

};
