#ifndef LISTLINKED_H
#define LISTLINKED_H

#include "List.h"
#include "Node.h"
#include <stdexcept>

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* head;
    int n;

public:
    ListLinked() : head(nullptr), n(0) {}

    ~ListLinked() {
        while (!empty()) {
            remove(0);
        }
    }

    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) throw std::out_of_range("Posicion fuera de rango");
        if (pos == 0) {
            head = new Node<T>(e, head);
        } else {
            Node<T>* prev = head;
            for (int i = 0; i < pos - 1; i++) {
                prev = prev->next;
            }
            prev->next = new Node<T>(e, prev->next);
        }
        n++;
    }

    void append(T e) override { insert(n, e); }
    void prepend(T e) override { insert(0, e); }

    T remove(int pos) override {
        if (pos < 0 || pos >= n) throw std::out_of_range("Posicion fuera de rango");
        Node<T>* target;
        T data;
        if (pos == 0) {
            target = head;
            head = head->next;
        } else {
            Node<T>* prev = head;
            for (int i = 0; i < pos - 1; i++) {
                prev = prev->next;
            }
            target = prev->next;
            prev->next = target->next;
        }
        data = target->data;
        delete target;
        n--;
        return data;
    }

    T get(int pos) override {
        if (pos < 0 || pos >= n) throw std::out_of_range("Posicion fuera de rango");
        Node<T>* current = head;
        for (int i = 0; i < pos; i++) {
            current = current->next;
        }
        return current->data;
    }

    int search(T e) override {
        Node<T>* current = head;
        int index = 0;
        while (current) {
            if (current->data == e) return index;
            current = current->next;
            index++;
        }
        return -1;
    }

    bool empty() override { return head == nullptr; }
    int size() override { return n; }

    friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
        Node<T>* current = list.head;
        while (current) {
            out << current->data << " ";
            current = current->next;
        }
        return out;
    }
};

#endif
