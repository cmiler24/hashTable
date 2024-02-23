#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    struct Node* next;
};

class LinkedList {
    Node* head;
    
    public:
        //constructor
        LinkedList();
        
        // init methods
        void add(string key);
        Node* get(Node* node);
        void printList();
        int getSize();
        Node * getHead();
};

LinkedList::LinkedList() {
    head = NULL;
}

// add new node to LinkedList
void LinkedList::add(string key) {
    //create new node
    Node* node = new Node();
    node->data = key;   // add key to node's data variable

    if (head == NULL) {
        head = node;
        return;
    }
    // traverse the list until you find tail, then add new node to tail
    Node* temp = head;
    while(temp->next) {
        temp = temp->next;
    }
    temp->next = node;
}

// retrieve node from LinkedList
Node* LinkedList::get(Node* node) {
    Node* temp = head;
    while (temp->next) {
        if (temp->data == node->data) {
            return node;
        }
        temp = temp->next;
    }
    return NULL;
};

Node * LinkedList::getHead() {
    return head;
}

int LinkedList::getSize() {
    Node* temp = head;
    int cap = 0;
    while(temp->next) {
        cap++;
        temp = temp->next;
    }
    return cap;
}

void LinkedList::printList() {
    Node* temp = head;
    while (temp->next) {
        // printf(" %s ", temp->data);
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << endl; // new string for the next print
}