#pragma once
#include "Employee.h"
namespace collections
{
    using namespace payroll;
    class node
    {
    private:
        node *next() { return this->right; }
        const Employee *item() { return data; }
        node(const Employee *data)
        {
            this->data = data;
            right = nullptr;
        }
        node *right;
        const Employee *data;
        friend class list;
        friend class list_cursor;
    };

    class list_cursor
    {
    public:
        bool has_next() { return current->next() != nullptr; }
        const Employee *next()
        {
            if (current != nullptr)
            {
                const Employee *data = current->item();
                current = current->next();
                return data;
            }
            else
                return nullptr;
        }

    private:
        list_cursor(node *head) : current(head) {}
        node *current;
        friend class list;
    };

    class list
    {
    public:
        list() : head(nullptr), tail(nullptr) {}
        list(const list& other)
        {
            head = tail = nullptr;
            auto cursor = other.begin();
            const Employee* e = nullptr;
            while ((e = cursor.next()) != nullptr)
                add(e);
        }
        ~list()
        {
            node* curr = head;
            while (curr != nullptr)
            {
                node* next = curr->right;
                delete curr;
                curr = next;
            }
        }
 
        void add(const Employee *e);
        list_cursor begin() const { return list_cursor(head); }
    private:
        node *head;
        node *tail;
    };

}