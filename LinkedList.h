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
        int length;
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
    length = 0;
}

// add new node to LinkedList
void LinkedList::add(string key) {
    //create new node
    Node* node = new Node();
    node->data = key;   // add key to node's data variable

    if (head == NULL) {
        head = node;
        head->next = NULL;
        length++;
        return;
    }
    // traverse the list until you find tail, then add new node to tail

    Node* temp = head;
    int count = 0;
    while(count < length - 2) {
        temp = temp->next;
        count++;
    }
    temp->next = node;
    length++;
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
   return length;
}

void LinkedList::printList() {
    Node* temp = head;
    if (length == 1) {
        cout << "data: " << head->data << endl;
        return;
    }

    while (temp->next) {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << endl; // new string for the next print
}