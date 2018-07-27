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
        T data = T();
        std::unique_ptr<Node> next {nullptr};

        Node() = default;
        Node(T _data): data(_data) {}
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
    void pop_back();

    void push_front(T value);
    void pop_front();

    void insert();

    void traverse() const;

private:
    std::unique_ptr<Node> make_unique_ptr_to_node() const;
    std::unique_ptr<Node> make_unique_ptr_to_node(T value) const;
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

template<class T>
void SinglyList<T>::pop_back()
{

}

template<class T>
void SinglyList<T>::push_front(T value)
{
    if(head == nullptr)
    {
        push_back(value);
    }

    auto new_head = make_unique_ptr_to_node(value);
    new_head->next = std::move(head);
    head = std::move(new_head);
}

template<class T>
void SinglyList<T>::pop_front()
{
    if(head)
    {
       head = std::move(head->next);
    }
}

template <class T>
void SinglyList<T>::traverse() const
{
    auto *temp = head.get();
    while (temp)
    {
        std::cout << temp->data << ' ' << std::endl;
        temp = temp->next.get();
    }
}

template <class T>
std::unique_ptr<typename SinglyList<T>::Node> SinglyList<T>::make_unique_ptr_to_node() const
{
    return std::make_unique<typename SinglyList<T>::Node>();
}

template <class T>
std::unique_ptr<typename SinglyList<T>::Node> SinglyList<T>::make_unique_ptr_to_node(T value) const
{
    return std::make_unique<typename SinglyList<T>::Node>(value);
}
