#ifndef _Node_h_
#define _Node_h_

#include <stdlib.h>

/*
Class Node declaration
*/
class Node {
    public:
        //constructor
        Node(int in = -1, Node *nPtr = NULL) {num = in, next = nPtr;}
        
        int num;
        Node *next;
};




#endif