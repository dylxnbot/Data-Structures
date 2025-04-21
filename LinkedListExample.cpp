#include <iostream>
using namespace std;

// Creating a node structure
struct Node {
    int data;
    Node *link;
};
typedef Node* nodePtr;

void insert(nodePtr& head, int data){
    nodePtr newNode = new Node;
    newNode->data = data;
    newNode->link = NULL;

    nodePtr tmp = head;
    while(tmp->link != NULL) {
        tmp = tmp->link;
    }
    tmp->link = newNode;
}

int main() {
    nodePtr head;
    head = new Node;
    head->data = 20;
    head->link = NULL;
     
insert (head, 30);
nodePtr tmp;
tmp = head;

while(tmp != NULL) {
    cout << tmp->data << endl;
    tmp = tmp->link;
}
}