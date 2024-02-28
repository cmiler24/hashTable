#include <iostream>
#include <string>
#include <cmath>
#include "LinkedList.h"
// You are free to use additional libraries as long as it's not PROHIBITED per instruction.
using namespace std;

int hash_function(string text);

class HashTable {
    LinkedList * hashTable;
    int capacity;
    int htSize;
    
    public:
    HashTable(int n);
    void addToTable(string key);
    void printFirstFive();
    void printSlotLengths();
    bool isList(int index);
    int getLength();
};

HashTable::HashTable(int numSlots) {
    cout << "numSlots" << numSlots << endl;
    hashTable = new LinkedList[numSlots];
    
    for (int i = 0; i < numSlots; i++) {
        LinkedList * list = new LinkedList();
        hashTable[i] = *list;
        hashTable[i].length = 0;
    }
    capacity = numSlots;
    htSize = 0;
};

bool HashTable::isList(int i) {
    if (hashTable[i].length > 1) {
        return true;
    } else {
        return false;
    }
}

void HashTable::addToTable(string key) {
    cout << "adding to table " << endl;
    int index = 0;

    hashTable[index].add(key);
    htSize++;
    cout << "added" << endl;
};

int HashTable::getLength() {
    return capacity;
}

// void HashTable::printFirstFive() {
//     for (int i = 0; i < 5; i++) {
//         // access hashtable at first slot
//         if (hashTable[i].length > 0) {
//             hashTable[i].printList();       
//         } 
//     }
// };

// void HashTable::printSlotLengths() {
//     for (int i = 0; i < htSize; i++) {
//         cout << "Slot " << i << ": " << hashTable[i].length << endl;
//     }
// }
