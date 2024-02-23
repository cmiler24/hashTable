#include <iostream>
#include <string>
#include <cmath>
#include "LinkedList.h"
// You are free to use additional libraries as long as it's not PROHIBITED per instruction.
using namespace std;

int hash_function(string text);

class HashTable {
    string * hashTable;
    int capacity;
    int htSize;
    
    public:
    HashTable(int n);
    void addToTable(string key);
    void printFirstFive();
    void printSlotLengths();
    bool isList(int index);
    int getSize();
};

HashTable::HashTable(int numSlots) {
    hashTable = new string[numSlots];
    capacity = numSlots;
    htSize = 0;
};

// bool HashTable::isList(int i) {
//     // string * ptr = &(*hashTable); // ptr to address of first index of hashTable array
//     // // ptr points to address of content at index 1

//     // ptr = ptr+i;
//     // // *(ptr) // element in hashTable found.

//     // if ((*ptr).find(",") != string::npos) {
//     //     cout << "Index contains a list" << endl;
//     //     cout << "Element at index " << i << " is " << *ptr << endl;

//     //     return true;
//     // }
//     // else {
//     //     cout << "Contents at index " << i << " " << *ptr << endl;
//     //     return false;
//     // }
// }

int HashTable::getSize() {
    return htSize;
};

void HashTable::addToTable(string key) {
    
    cout << " adding to table " << endl;
    int index = hash_function(key);

    if (hashTable[index] == "") {
        hashTable[index] = key; // int pointer to point to ith index in hashTable array
        cout << "added " << endl;
    }
    else {
        cout << " added list " << endl;
        hashTable[index] += "," + key;
        // LinkedList * list = new LinkedList();
    }
    



    // if (getSize() == 0) {
    //     // the first item added to the table
    // }

    // cout << "string * is pointing to " << &(*hashTable)[index] << endl;
    // ptr = ptr+index;    // find hashTable's index by offsetting to index from index 0

    // // cout << "Adding key '" << key << "' to index '" << index << "'" << endl;
    // // if hashTable is a LinkedList! add to end of list
    // if (isList(index)) {
    //     // create a new LinkedList
    //     LinkedList* list = new LinkedList();
    //     // add key as last item in the list
    //     list->add(key);
    //     htSize++;
    //     // set list at hashtable index;
    //     // assign hashTable[i] = head node of linkedList
    //     // *ptr = list->getHead();
    //     cout << "this will be assigned to the table: " << list->getHead() << endl;
    // } else { // otherwise, insert index (OA style)
    //     *ptr = key;
    // }
};

void HashTable::printFirstFive() {
    for (int i = 0; i < 5; i++) {
        // access hashtable at first slot
        // if (isList(i)) {
            // hashTable[i].printList();
            cout << "printing: " << *(hashTable+i) << endl;
        // }
        // else {
        //     cout << *(hashTable+i) << endl;
        // }
    }
};

void HashTable::printSlotLengths() {
    for (int i = 0; i < htSize; i++) {
        cout << "Slot " << i << ": " << sizeof(hashTable[i]);
    }
}
