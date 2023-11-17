#pragma once

namespace collections
{
    template <typename T>
    class node
    {
    private:
        node<T> *next() { return this->right; }
        T *item() { return data; }
        node(T *data)
        {
            this->data = data;
            right = nullptr;
        }
        node<T> *right;
        T *data;
        template <typename>
        friend class list;
        template <typename>
        friend class list_cursor;
    };

    template <typename T>
    class list_cursor
    {
    public:
        bool has_next() { return current->next() != nullptr; }
        T *next()
        {
            if (current != nullptr)
            {
                T *data = current->item();
                current = current->next();
                return data;
            }
            else
                return nullptr;
        }

    private:
        list_cursor(node<T> *head) : current(head) {}
        node<T> *current;
        template <typename>
        friend class list;
    };

    template <typename T>
    class list
    {
    public:
        list() : head(nullptr), tail(nullptr) {}
        list(const list &other) = delete;

        ~list()
        {
            node<T> *curr = head;
            while (curr != nullptr)
            {
                node<T> *next = curr->right;
                delete curr;
                curr = next;
            }
        }
        list_cursor<T> begin() const { return list_cursor<T>(head); }
        void add(T *e)
        {
            auto n = new node<T>(e);
            if (tail != nullptr)
                tail->right = n;
            else
                head = n;
            tail = n;
        }

    private:
        node<T> *head;
        node<T> *tail;
    };

}