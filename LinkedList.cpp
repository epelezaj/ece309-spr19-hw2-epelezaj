// ECE 209, Spring 2019
// Homework 2, Problem 2

#include "Item.h"
#include <stdio.h>

//Linked List class
class List {
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
    List() {
        head = nullptr;
        tail = nullptr;
    }

    List(const List &l) {
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

    ~List() {
        Item t;
        while (!empty()) {
            remove(t);
        }
    }

    int length() {
        int count = 0;
        ListNode *i = head;
        while (i) {
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
        if (num > length() + 1) return false;
        ListNode *next = head;
        ListNode *prev = nullptr;
        for (int x = 0; x < num - 1; x++) {
            prev = next;
            next = next->getNext();
        }
        auto newNode = new ListNode(i);
        newNode->setNext(next);
        prev->setNext(newNode);
        return true;
    }
};

// main function to demonstrate class
int main() {
    List list1; //uses default constructor to create an empty list
    printf("The list is currently %d nodes long\n", list1.length());

    const char *first = "first string";
    Item itema(1, first);
    list1.append(itema); //appends to list
    printf("Adding item  #%d to the list\n", itema.getKey());
    const char *second = "second string";
    Item itemb(2, second);
    list1.append(itemb); //appends to list
    printf("Adding item  #%d to the list\n", itemb.getKey());
    const char *third = "third string";
    Item itemc(3, third);
    list1.append(itemc); //append to list
    printf("Adding item  #%d to the list\n", itemc.getKey());
    printf("The list is currently %d nodes long\n\n", list1.length()); //prints length of list

    Item copy;
    list1.remove(copy); //removes first node of the list
    printf("Item #%d was removed\n", copy.getKey());
    printf("The list is currently %d nodes long\n\n", list1.length());

    list1.insert(itema, 2); //inserts item into third node of list
    printf("Item #%d was added to position 2\n", itema.getKey());
    printf("The list is currently %d nodes long\n\n", list1.length());

    List list2 = list1;
    printf("The copied list is currently %d nodes long\n", list2.length());

    list1.empty();
    printf("The list is currently %d nodes long\n", list1.length());
}