#pragma once
#include <vector>

template<typename T>
class Field {
public:
    using fieldAlias = std::vector<std::vector<T*>>;

public:
    Field() = default;
    explicit Field(std::pair<int, int> size) noexcept :
        field_(fieldAlias(size.first, std::vector<T*>(size.second))) {}

    void resize(std::pair<int, int> size) {
        field_.resize(size.first, std::vector<T*>(size.second));
    }

    std::pair<int, int> size() const {
        if (field_.empty()) return {0, 0};
        return {field_.size(), field_[0].size()};
    }

    Field(const Field&) = default;
    Field& operator=(const Field&) = default;
    Field(Field&&) noexcept = default;
    Field& operator=(Field&&) noexcept = default;
    ~Field() = default;

private:
    std::vector<std::vector<T*>> field_;

};
