// ECE 309 - Spring 2019
// Homework 2, problem 1

#ifndef HW2_ITEM_H
#define HW2_ITEM_H


class Item {
private:
    int key;
    const char *value;
public:
    Item(int k = 0, const char *v = nullptr) {
        key = k;
        value = v;
    }

    int getKey() {
        return key;
    }

    const char *getValue() {
        return value;
    }

    Item(const Item &i) {
        key = i.key;
        value = i.value;
    }
};


#endif //HW2_ITEM_H
