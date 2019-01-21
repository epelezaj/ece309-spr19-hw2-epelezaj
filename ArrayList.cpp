// ECE 209, Spring 2019
// Homework 2, Problem 3

#include "Item.h"
#include <stdio.h>

// ArrayList class
class ArrayList{
private:
    Item *array;
    int len = 0;
    int size = 0;
public:
    ArrayList(){
        array = new Item[3];
        size = 3;
        len = 0;
    };
    ArrayList(const ArrayList &al){
        len = al.len;
        size = al.size;
        auto array = new Item[size];
        for(int x=0;x<len;x++){
            array[x] = al.array[x];
        }
    }
    ~ArrayList(){
        delete array;
    }
    int length(){
        return len;
    }
    void append(const Item &i){
        if(len+1>size){
            auto newarray = new Item[size+3];
            for(int x=0;x<len;x++){
                newarray[x]=array[x];
            }
            delete array;
            array = newarray;
            size+=3;
        }
        array[len] = i;
        len += 1;
    }
    bool remove(Item &i){
        if (len==0) return false;
        i = array[0];
        for(int x=0;x<len-1;x++){
            array[x]=array[x+1];
        }
        len--;
        return true;
    }
    bool empty(){
        return len==0;
    }
    bool insert(const Item &i, int num){
        if(num>len+1) return false;
        if(len+1>size){
            auto newarray = new Item[size+3];
            for(int x=0;x<len;x++){
                newarray[x]=array[x];
            }
            delete array;
            array = newarray;
            size+=3;
        }
        for (int x=len+1;x>num;x--){
            array[x]=array[x-1];
        }
        array[num-1] = i;
        len++;
        return true;
    }
};

// main function to demonstrate the class
int main() {
    ArrayList list1; //uses default constructor to create an empty list
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

    ArrayList list2 = list1;
    printf("The copied list is currently %d nodes long\n", list2.length());

    list1.empty();
    printf("The list is currently %d nodes long\n", list1.length());
    return 0;
}

