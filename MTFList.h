//Header file for MTFList

#ifndef _MTF_LIST_H_
#define _MTF_LIST_H_



#include "Node.h"
#include <iostream>

using namespace std;


/*
Class Linked List declaration
*/
class LL {
    private:
        int count;
        double traversal;
        Node *head;
        Node *tail;
    
    public:
        LL();
        ~LL();
        void push_front(int);
        void search(int);
        void move_to_front(Node*);
        void pop_front();
        void clear();
        void display();
        double get_traversal();

};


//LL implementation
//default constructor
LL::LL() {
    head = NULL;
    tail = NULL;
    count = 0;
    traversal = 0;
}

//deconstructor
LL::~LL() {
    if(head != NULL)
        clear();
    delete head;
    delete tail;
 //   cout << "done deconstructing" << endl;
}

//add node to front function
void LL::push_front(int input){
    Node *newNode;

    newNode = new Node(input, head);

    newNode->next = head;
    
    if(head != NULL) {
       // head->next = NULL; //this is a test
    }
    else { //list is empty
        tail = newNode;
    }
    head = newNode;

    count++;
}

//Search function - item searched for will be moved to front of list
void LL::search(int find){
    if(head != NULL) {
        Node* itr = head;
        Node* trail = NULL;
        bool found = false;
        while(itr != NULL && !found){
      //      cout << "itr is pointing at " << itr->num << endl;
            traversal++;
            if(itr->num == find) {
               found = true;
      //         cout << "inside of found if block in search function" << endl;
               //move_to_front(itr);
               if(trail != NULL){
                   if(itr == tail)
                        tail = trail;
                   trail->next = itr->next;
                   itr->next = head;
                   head = itr;
               }
               return;
            }
            trail = itr;
            itr = itr->next;
        } //end while
      //  if(!found)
    //        cout << find << " not found in list" << endl;
    }
}

//move to front function
void LL::move_to_front(Node* toMove) {
    if(toMove == head){
        //all good already first
    }
    else {
       
    }
} //end function

//remove Node from front
void LL::pop_front() {
   // cout << "in pop_front()" << endl;
    if(head == NULL) {
        //list is empty
    }
    else if(head == tail){
        //one node in list
        delete head;
        head = NULL;
        tail = NULL;
        count --;
    }
    else {
        Node *current = head;
     //   cout << "getting rid of " << current->num << endl;
        //tail = tail->prev;
        //tail->next = NULL;
        //tail->prev = current->prev;

        head = head->next;
        delete current;

       // head = current->next;

        count--;
    }
}

//Clear function implementation
void LL::clear() {
  //  cout << "in clear" << endl;
    while(tail != NULL){
        pop_front();
    }
}

//Display() function implementation
void LL::display() {
   // cout << "There are: " << count << " Nodes in the list." << endl;
    cout << "MTFList Display: " << endl;
    Node *current = head;
   // int nodeNum = 0;

    while (current != NULL) {
  //    cout << "Node #" << nodeNum++ << " = " <<current->num << endl;
        cout << current->num << " ";
        current = current->next;
    }
   // cout << "Head is pointing at the num: " << head->num << endl;
   // cout << "Tail is pointing at the num: " << tail->num << endl;

   // cout << "out of while loop" << endl;
}

//traversal functino
double LL::get_traversal() {
    return traversal;
}




#endif