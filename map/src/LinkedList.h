#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include "iostream"

template<class T> class LinkedList {
    class Node {
    public:
        T data;
        Node* next;

        Node(T data)
        {
            this->data = data;
            this->next = nullptr;
        }
    };

    Node* head;
    Node* tail;

public:
    LinkedList()
    {
        head = nullptr;
        tail = head;
    }

    LinkedList(const LinkedList& list)
    {
        head = nullptr;
        tail = head;
        Node* nextNode = list.head;

        while (nextNode != nullptr) {
            add(nextNode->data);
            nextNode = nextNode->next;
        }
    }

    ~LinkedList() {
        Node* nextNode = head;

        while (nextNode != nullptr) {
            Node* temp = nextNode->next;
            delete nextNode;
            nextNode = temp;
        }
    }

    bool isEmpty() const
    {
        return head == nullptr;
    }

    void add(T value)
    {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    bool remove(const T& value)
    {
        if (head->data == value) {
            Node* temp = head->next;
            delete head;
            head = temp;
            return true;
        }

        Node* currentNode = head;
        Node* nextNode = currentNode->next;

        while (nextNode != nullptr) {
            if (nextNode->data == value) {
                Node* temp = nextNode->next;
                delete nextNode;
                currentNode->next = temp;
                return true;
            }
            currentNode = currentNode->next;
            nextNode = currentNode->next;
        }

        return false;
    }

    bool contains(const T& value)
    {
        Node* nextNode = head;

        while (nextNode != nullptr) {
            if (nextNode->data == value) {
                return true;
            }
            nextNode = nextNode->next;
        }

        return false;
    }

    T* getPtr(const T& value) {
        Node* nextNode = head;

        while (nextNode != nullptr) {
            if (nextNode->data == value) {
                return &(nextNode->data);
            }
            nextNode = nextNode->next;
        }

        return nullptr;
    }

    LinkedList& operator=(const LinkedList& list)
    {
        Node* nextNode = head;

        while (nextNode != nullptr) {
            Node* temp = nextNode->next;
            delete nextNode;
            nextNode = temp;
        }


        head = nullptr;
        tail = head;
        nextNode = list.head;

        while (nextNode != nullptr) {
            add(nextNode->data);
            nextNode = nextNode->next;
        }

        return *this;
    }

private:
    friend std::ostream& operator<<(std::ostream& s, const LinkedList& list)
    {
        Node* nextNode = list.head;

        s << "[";
        while (nextNode != nullptr) {
            s << nextNode->data;
            if (nextNode->next != nullptr) {
                s << ", ";
            }
            nextNode = nextNode->next;
        }
        s << "]" << std::endl;

        return s;
    }

};

#endif