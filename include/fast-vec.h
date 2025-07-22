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
    private:
        Node() = default;
        Node(const T& value, FastVec<T>* owner, Node* p = nullptr) : 
        value_(value), owner_(owner), prev(p), next(nullptr) {}
        T value_;
        std::unique_ptr<Node> next;
        Node* prev;
        const FastVec<T>* const owner_;
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
    void push_back(const T& value) {
        auto newNode = std::make_unique<Node>(value, this, tail);
        if (head == nullptr) {
            head = std::move(newNode);
            tail = head.get();
        } else {
            tail->next = std::move(newNode);
            tail = tail->next.get();
        }
    }
    void pop_back() {
        if (tail == nullptr) throw std::out_of_range("cannot erase element from empty container");
        erase(tail);
    }
    void erase(Node* node) {
        if (node == nullptr) throw std::invalid_argument("cannot delete nullptr node");
        if (node->owner != this) throw std::invalid_argument("the node not in that container");

        if (node->next != nullptr) node->next->prev = node->prev;
        else tail = node->prev;

        if (node->prev != nullptr) node->prev->next = std::move(node->next);
        else head = std::move(node->next);
    }
    ~FastVec() = default;

private:
    std::unique_ptr<Node> head;
    Node* tail;

};
