#pragma once
#include <iostream>
#include <limits>

template <class T>
class SinglyList
{
  private:
    struct Node
    {
        T data;
        Node *next = nullptr;
    } *head = nullptr;

  public:
//    class Iterator
//    {
//    public:
//        Iterator() = default;

//    };

  public:
    SinglyList() = default;
    virtual ~SinglyList();
    SinglyList(const SinglyList &);
    SinglyList(SinglyList &&);
    SinglyList &operator=(const SinglyList &);
    SinglyList &operator=(SinglyList &&);

    void push_back(T value);
    Node getHead();
    void removeHead();
    void traverse() const;

  private:
    Node *createNode();
};

template <class T>
SinglyList<T>::~SinglyList()
{
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

template <class T>
SinglyList<T>::SinglyList(const SinglyList &other)
    : head{new Node{*(other.head)}}
{
}

template <class T>
SinglyList<T>::SinglyList(SinglyList &&other)
    : head{other.head}
{
    other.head = nullptr;
}

template <class T>
SinglyList<T> &SinglyList<T>::operator=(const SinglyList &other)
{
    if (other != *this)
    {
        delete head;
        head = nullptr;
        head = new Node{*(other.head)};
    }
    return *this;
}

template <class T>
SinglyList<T> &SinglyList<T>::operator=(SinglyList &&other)
{
    if (other != *this)
    {
        delete head;
        head = other.head;
        other.head = nullptr;
    }
    return *this;
}

template <class T>
void SinglyList<T>::push_back(T value)
{
    Node *temp = createNode();
    temp->data = value;

    if (head == nullptr)
    {
        head = temp;
    }
    else
    {
        Node *p = head;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

template <class T>
typename SinglyList<T>::Node SinglyList<T>::getHead()
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
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

template <class T>
void SinglyList<T>::traverse() const
{
    Node *temp = head;

    while (temp)
    {
        std::cout << temp->data << ' ' << std::endl;
        temp = temp->next;
    }
}

template <class T>
typename SinglyList<T>::Node *SinglyList<T>::createNode()
{
    Node *temp = new Node;
    temp->next = nullptr;
    return temp;
}
