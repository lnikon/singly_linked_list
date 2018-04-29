#pragma once
#include <iostream>
#include <limits>
#include <memory>
#include <utility>

template <class T>
class SinglyList
{
private:
    struct Node
    {
        T data;
        std::unique_ptr<Node> next {nullptr};
    };

    std::unique_ptr<Node> head {nullptr};

public:
    SinglyList() = default;
    ~SinglyList() = default;

    SinglyList(const SinglyList &) = delete;
    SinglyList &operator=(const SinglyList &) = delete;

    SinglyList(SinglyList &&) = default;
    SinglyList &operator=(SinglyList &&) = default;

    void push_back(T value);
    std::unique_ptr<Node> pop_back();

    void push_front(T value);
    std::unique_ptr<Node> pop_front();

    void traverse() const;

private:
    std::unique_ptr<Node> make_unique_ptr_to_node();
};

template <class T>
void SinglyList<T>::push_back(T value)
{
    auto temp = make_unique_ptr_to_node();
    temp->data = value;

    if (head == nullptr)
    {
        head = std::move(temp);
    }
    else
    {
        auto *p = head.get();
        while (p->next != nullptr)
        {
            p = p->next.get();
        }
        p->next = std::move(temp);
    }
}

template <class T>
void SinglyList<T>::traverse() const
{
    Node *temp = head.get();

    while (temp)
    {
        std::cout << temp->data << ' ' << std::endl;
        temp = temp->next.get();
    }
}

template <class T>
std::unique_ptr<typename SinglyList<T>::Node> SinglyList<T>::make_unique_ptr_to_node()
{
    return std::make_unique<typename SinglyList<T>::Node>();
}
