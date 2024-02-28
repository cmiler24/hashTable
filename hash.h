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
    int htSiZe;
    
    public:
    HashTable(int n);
    void addToTable(string key);
    void printFirstFive();
    void printSlotLengths();
    bool isList(int index);
    int linearProbe(int index);
    int getLength();
    double calculateStdVar(int k, int n);
};

HashTable::HashTable(int numSlots) {
    hashTable = new LinkedList[numSlots];
    for (int i = 0; i < numSlots; i++) {
        LinkedList * list = new LinkedList();
        hashTable[i] = *list;
        hashTable[i].length = 0;
    }
    capacity = numSlots;
    htSiZe = 0;
};

bool HashTable::isList(int i) {
    if (hashTable[i].length > 1) {
        return true;
    } else {
        return false;
    }
}

void HashTable::addToTable(string key) {
    int index = hash_function(key);

    // resolve collision by hashing
    // if collision happens, linear probe
            // if (hashTable[i].length > 0) {
            //     for (index; index < capacity; index++) {
            //     if (hashTable[index].length > 0) {
            //         index+=1;
            //     }
            // }

            // // concactenate an extra char to the key
            //     index = addToTable(key+'a');
            // }

    hashTable[index].add(key);
    htSiZe++;
    // cout << "added " << key << " to index " << index << endl;
};

int HashTable::getLength() {
    return capacity;
}

void HashTable::printFirstFive() {
    for (int i = 0; i < 5; i++) {
        // access hashtable at first slot
        if (hashTable[i].length >= 0) {
            cout << "Slot " << i << ": ";
            hashTable[i].printList(); 
        } 
    }
};

void HashTable::printSlotLengths() {
    for (int i = 0; i < capacity; i++) {
        cout << "Slot " << i << ": " << hashTable[i].length << endl;
    }
}

double HashTable::calculateStdVar(int k, int n) {
    double average = static_cast<double>(k) / n;
    double sum = 0;
    for (int i = 0; i < k; i++) {
        sum += pow(hashTable[i].length - average, 2);
    }
    double std_dev = sqrt((1/static_cast<double>(k))*(sum));
    return std_dev;
}
