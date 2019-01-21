// ECE 209, Spring 2019
// Homework 2, Problem 2

// LinkedList class

// main function to demonstrate class
#include "Item.h"


class list {
private:
    class ListNode {
    private:
        Item item;
        ListNode *next;
    public:
        ListNode(Item a) {
            item = a;
            next = nullptr;
        }

        ListNode *getNext() {
            return next;
        }

        void setNext(ListNode *n) {
            next = n;
        }

        Item getItem() {
            return item;
        }
    };

    ListNode *head;
    ListNode *tail;
public:
    list() {
        head = nullptr;
        tail = nullptr;
    }

    list(const list &l) {
        head = new ListNode(l.head->getItem());
        ListNode *newlist = head;
        ListNode *oldlist = l.head;
        while (oldlist->getNext()) {
            newlist->setNext(new ListNode(oldlist->getItem()));
            newlist = newlist->getNext();
            oldlist = oldlist->getNext();
        }
        tail = new ListNode(l.tail->getItem());
    }

    ~list() {
        Item t;
        while (!empty()) {
            remove(t);
        }
    }

    int length() {
        int count = 0;
        ListNode *i = head;
        while (!i) {
            i = i->getNext();
            count++;
        }
        return count;
    }

    void append(const Item &i) {
        auto *node = new ListNode(i);
        if (!head) {
            head = node;
            tail = node;
        } else {
            tail->setNext(node);
            tail = node;
        }
    }

    bool remove(Item &copy) {
        if (!empty()) {
            copy = head->getItem();
            ListNode *tmp = head->getNext();
            delete head;
            head = tmp;
            if (!tmp) {
                tail = nullptr;
            }
            return true;
        }
        return false;
    }

    bool empty() {
        return head == nullptr;
    }

    bool insert(const Item &i, int num) {
        int x;
        ListNode *p = head;
        auto node = new ListNode(i);
        for (x = num; x > 0; x--) {
            if (!(p = p->getNext())) return false;
        }
        p->setNext(node);
        return true;
    }
};

int main() {
    return 0;
}
