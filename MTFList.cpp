/*
CS 160 MTFList project 1

Clyde Leef, 2021

*/

#include "MTFList.h"

/*
Class Node declaration
*/
class Node {
    public:
        //constructor
        Node(int in = -1, Node *nPtr = NULL, Node *pPtr = NULL) {num = in, next = nPtr, prev = pPtr;}
        
        int num;
        Node *next;
        Node *prev;
};

/*
Class Linked List declaration
*/
class LL {
    private:
        int count;
        Node *head;
        Node *tail;
    
    public:
        LL();
        ~LL();
        void push_front(int);
        void search(int);
        void pop_back();
        void clear();
        bool is_empty();

};

//Driver
int main(int argc, const char * argv[]){

    return 0;
}


//LL implementation
//default constructor
LL::LL() {
    head = NULL;
    tail = NULL;
    count = 0;
}

//deconstructor
LL::~LL() {
    if(head != NULL)
        clear();
}

//add node to front function
void LL::push_front(int input){
    Node *newNode;

    newNode = new Node(input, head, NULL);

    newNode->next = head;
    newNode->prev = NULL;
    
    if(head != NULL) {
        head->prev = newNode;
    }
    head = newNode;

    count++;
}

//Search function - item searched for will be moved to front of list
void LL::search(int find){

}

//remove Node from back
void LL::pop_back() {

}