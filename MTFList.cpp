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
        void move_to_front(Node*);
        void pop_back();
        void clear();
        void display();

};

//Driver
int main(int argc, const char * argv[]){
    try{
        LL List;
        /*
        ifstream File;
        if(argc < 2)
            cout << "not enough arguments" << endl;
        File.open(argv[1]);

        int count;
        File >> count;
        int hold;
        for(int i = 1; i < count; i++) {
            File >> hold;
            List.push_front(hold);
        }
        */
        List.push_front(1);
        List.push_front(2);
        List.push_front(3);
      //  cout << "in main before display" <<endl;
        List.display();
        cout << "Back in main" << endl;
      //  List.pop_back(); doesnt work yet
        List.pop_back();
        /*
        File >> count;
        for(int i = 1; i < count; i++) {
            File >> hold;
            List.search(hold);
        }
        */
        List.display();


    }
    catch(exception &e) {
        cout << "Exception caught in main: " << e.what() << endl;
    }

    cout << "made it to the end of main" << endl;
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
        bool found = false;
        while(itr != NULL && !found){
            if(find == itr->num) {
               found = true;
               move_to_front(itr);
            }
            itr = itr->next;
        } //end while
        if(!found)
            cout << find << " not found in list";
    }
}

//move to front function
void LL::move_to_front(Node* toMove) {
    if(toMove == head){
        //all good already first
    }
    else {
        toMove->prev->next = toMove->next;
        toMove->next->prev = toMove->prev;
        toMove->prev = NULL;
        toMove->next = head;
        head->prev = toMove;
        head = toMove;
    }
} //end function

//remove Node from back
void LL::pop_back() {
    cout << "in pop_back()" << endl;
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
        Node *current = tail->prev;

        //tail = tail->prev;
        //tail->next = NULL;
        //tail->prev = current->prev;

        current->next = NULL;

        delete tail;

        tail = current;
        count--;
    }
}

//Clear function implementation
void LL::clear() {
    cout << "in clear" << endl;
    while(tail != NULL){
        pop_back();
    }
}

//Display() function implementation
void LL::display() {
    cout << "There are: " << count << " Nodes in the list." << endl;

    Node *current = head;
    int nodeNum = 0;

    while (current != NULL) {
        cout << "Node #" << nodeNum++ << " = " <<current->num << endl;
        current = current->next;
    }
    cout << "Head is pointing at the num: " << head->num << endl;
    cout << "Tail is pointing at the num: " << tail->num << endl;

    cout << "out of while loop" << endl;
}