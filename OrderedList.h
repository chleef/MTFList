#ifndef _ORDEREDLIST_H_
#define _ORDEREDLIST_H_

#include "Node.h"
//class OrderedList declaration

class OrderedList {
    private:
        int count;
        double traversal;
        Node *head;
        Node *tail;
    public:
        OrderedList();
        ~OrderedList();
        void push_front(int);
        bool bi_search(Node*, int);
        Node* middle(Node*, Node*);
        void merge_sort(Node**);
        Node* merge(Node*, Node*);
        void split_list(Node*, Node**, Node**);
        void pop_front();
        void clear();
        void display();
        double get_traversal();
        Node** get_headPtr();
        Node* get_head();
};


/*
Ordered List class implementation
*/

//default constructor
OrderedList::OrderedList() {
    head = NULL;
    tail = NULL;
    count = 0;
    traversal = 0;
}

//deconstructor
OrderedList::~OrderedList() {
    if(head != NULL)
        clear();
    delete head;
    delete tail;
}

//pushfront function
void OrderedList::push_front(int input) {
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

//binary search function (use when list is sorted)
bool OrderedList::bi_search(Node* top, int num) {
    Node* start = top;
    Node* last = NULL;
    
    do {
        //traversal++;
        Node* mid = middle(start, last);
        //middle is empty
        if(start == NULL)
            return false;
        //value present at middle
        if(mid->num == num)
            return true;
        else if(mid->num < num)
            start = mid->next;
        else
            last = mid;

    }
    while(last == NULL || last != start);

    return false;
}

//middle function to find midpoint of list for binary search
Node* OrderedList::middle(Node* front, Node* end) {
    if(front == NULL)
        return NULL;
    
    Node* slow = front;
    Node* fast = front->next;

    while(fast != end) {
        fast = fast->next;
        if(fast != end) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

//merge sort function
void OrderedList::merge_sort(Node **headRef) {
    Node* top = *headRef;
    Node* a;
    Node* b;

    if(top == NULL || top->next == NULL) {
        return;
    }

    split_list(top, &a, &b);

    merge_sort(&a);
    merge_sort(&b);

    *headRef = merge(a, b);
    }

//merge function to assist mergesort
Node* OrderedList::merge(Node* a, Node* b){
    Node* result = NULL;

    traversal++; //maybe it goes here?
    //base cases
    if(a == NULL)
        return b;
    else if(b == NULL)
        return a;
    
    if(a->num <= b->num) {
        result = a;
        result->next = merge(a->next, b);
    }
    else {
        result = b;
        result->next = merge(a, b->next);
    }
    return result;
}

//split_list to help with mergesort
void OrderedList::split_list(Node* source, Node** front, Node** back) {
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;

    //fast goes two nodes, slow one
    while(fast != NULL) {
       // traversal++; //maybe this goes here
        fast = fast->next;
        if(fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = NULL;

}


//pop front function (remove front item)
void OrderedList::pop_front() {
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

//clear the list
void OrderedList::clear() {
    //  cout << "in clear" << endl;
    while(tail != NULL){
        pop_front();
    }
}

//display the list
void OrderedList::display() {
    // cout << "There are: " << count << " Nodes in the list." << endl;
    cout << "OrderedList Display: " << endl;
    Node *current = head;
   // int nodeNum = 0;

    while(current != NULL) {
  //    cout << "Node #" << nodeNum++ << " = " <<current->num << endl;
        cout << current->num << " ";
        current = current->next;
    }
   // cout << "Head is pointing at the num: " << head->num << endl;
   // cout << "Tail is pointing at the num: " << tail->num << endl;

   // cout << "out of while loop" << endl;
}

//return number of traversals
double OrderedList::get_traversal() {
    return traversal;
}

Node** OrderedList::get_headPtr() {
    return &head;
}

Node* OrderedList::get_head() {
    return head;
}

#endif