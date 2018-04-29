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
    SinglyList(SinglyList &&);
    SinglyList &operator=(const SinglyList &) = delete;
    SinglyList &operator=(SinglyList &&);

    void push_back(T value);
    Node front();
    void removeHead();
    void traverse() const;

private:
    std::unique_ptr<Node> make_unique_ptr_node();
};

template <class T>
SinglyList<T>::SinglyList(SinglyList &&other)
{
    head->reset(other.head);
}

template <class T>
SinglyList<T> &SinglyList<T>::operator=(SinglyList &&other)
{
    if (other != *this)
    {
        head->reset(other.head);
    }
    return *this;
}

template <class T>
void SinglyList<T>::push_back(T value)
{
    auto temp = make_unique_ptr_node();
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
typename SinglyList<T>::Node SinglyList<T>::front()
{
    if (head)
    {
        return *head;
    }

    return Node();
}

template <class T>
void SinglyList<T>::removeHead()
{
    if (head)
    {
        head = std::move(head->next);
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
std::unique_ptr<typename SinglyList<T>::Node> SinglyList<T>::make_unique_ptr_node()
{
    return std::make_unique<typename SinglyList<T>::Node>();
}
