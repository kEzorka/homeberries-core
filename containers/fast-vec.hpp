#pragma once
#include <memory>
#include <stdexcept>

template<typename T>
class FastVec {
public:
    class Node {
    public:
        friend class FastVec<T>;
        ~Node() = default;
        Node() = default;
        Node(const T& value, FastVec<T>* owner, Node* p = nullptr) : 
        value_(value), owner_(owner), prev(p), next(nullptr) {}
        T value_;
    private:
        std::unique_ptr<Node> next = nullptr;
        Node* prev = nullptr;
        const FastVec<T>* const owner_ = nullptr;
    };

public:
    FastVec() = default;
    FastVec(const FastVec& copyVec) : 
        head(nullptr), tail(nullptr) 
    {
        for (Node* p = copyVec.head.get(); p != nullptr; p = p->next.get()) {
            push_back(p->value_);
        }    
    }
    FastVec& operator=(FastVec copyVec) {
        swap(copyVec);
        return *this;
    }
    void swap(FastVec& swapVec) noexcept {
        std::swap(head, swapVec.head);
        std::swap(tail, swapVec.tail);
    }
    Node* push_back(const T& value) {
        auto newNode = std::make_unique<Node>(value, this, tail);
        if (head == nullptr) {
            head = std::move(newNode);
            tail = head.get();
        } else {
            tail->next = std::move(newNode);
            tail = tail->next.get();
        }
        return tail;
    }
    void pop_back() {
        if (tail == nullptr) throw std::out_of_range("cannot erase element from empty container");
        erase(tail);
    }
    void clear() noexcept {
        while (head != nullptr) {
            Node* prev = tail->prev;
            if (prev) prev->next.reset();
            else head.reset();
            tail = prev;
        }
    }
    void erase(Node*& node) {
        if (node == nullptr) 
            throw std::invalid_argument("cannot delete nullptr node");
        if (node->owner_ != this) 
            throw std::invalid_argument("the node not in that container");

        if (node->next != nullptr) node->next->prev = node->prev;
        else tail = node->prev;

        if (node->prev != nullptr) node->prev->next = std::move(node->next);
        else head = std::move(node->next);
        
        node = nullptr;
    }
    ~FastVec() noexcept {
        clear();
    }

private:
    std::unique_ptr<Node> head = nullptr;
    Node* tail = nullptr;

};
