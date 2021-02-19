#ifndef _ORDEREDLIST_H_
#define _ORDEREDLIST_H_

#include "Node.h"
//class OrderedList declaration

class OrderedList {
    private:
        int count;
        unsigned traversal;
        int *aPtr;
    public:
        OrderedList();
        OrderedList(int);
        ~OrderedList();
        void push_back(int);
        bool bi_search(int, int, int);
        void merge_sort(int , int);
        void merge(int, int, int);
        void display();
        unsigned get_traversal();
        int get_count();
};


/*
Ordered List class implementation
*/

//default constructor
OrderedList::OrderedList() {
    count = 0;
    traversal = 0;
    aPtr = NULL;
}

OrderedList::OrderedList(int size){
    count = size;
    traversal = 0;
    aPtr = new int[size];
}

//deconstructor
OrderedList::~OrderedList() {
 //   cout << "made it to orderedlist deconstructor" << endl;
   // if(count > 0)
   //     delete aPtr; 
    //aPtr = NULL;
    delete aPtr;
  //  cout << "through orderedlist deconstructor" << endl;
}

//pushfront function
void OrderedList::push_back(int input) {
    if(aPtr == NULL) {
        aPtr = new int[1];
        aPtr[0] = input;
    }
    else { 
    int* tempArray = new int[count + 1];

    for(int i = 0; i < count; i++)
        tempArray[i] = aPtr[i];

    tempArray[count] = input;

    delete[] aPtr;

    aPtr = tempArray;
    }
    count++;
}

//binary search function (use when list is sorted)
bool OrderedList::bi_search(int start, int end, int num) {
    traversal++;

    if(end < start) //number isnt in list
        return false;
    
    int middle = start + (end - start) / 2;

    if(aPtr[middle] == num) { //found it
        return true;
       // traversal++;
    }
    if(aPtr[middle] < num) {//number is to the right
        return bi_search(middle + 1, end, num);
       // traversal++;
    }
    else  {//number is to the left {
        return bi_search(start, middle - 1, num);
       // traversal++;
    }
}

//merge sort function
void OrderedList::merge_sort(int start, int end) {
   // cout << "in merge sort, start = " << start << " end = " << end << endl;
    if(start >= end) {
       // cout << "merge_sort is returning" << endl;
        return;
    }
    int middle = start + (end - start)/2;
    
    merge_sort(start, middle);
    merge_sort(middle + 1, end);
  //  cout << "through merge_sort ing -- on to merging" << endl;
    //merge
    merge(start, middle, end);
  //  cout << "at the end of merge_sort function" << endl;
    }

//merge function to assist mergesort
void OrderedList::merge(int start, int middle, int end){
  //  cout << "in merge" << endl;
//merge 2nd attempt:

    int temp[end - start +1];

    int i = start;
    int j = middle +1;
    int k = 0;

    while(i <= middle && j <= end) {
        traversal++; //maybe it goes here
        if(aPtr[i] <= aPtr[j]) {
            temp[k] = aPtr[i];
            k++;
            i++;
        }
        else {
            temp[k] = aPtr[j];
            k++;
            j++;
        }
    }

    //add leftovers
    while(i<=middle) {
        temp[k] = aPtr[i];
        k++;
        i++;
    }

    while(j<=end) {
        temp[k] = aPtr[j];
        k++;
        j++;
    }

    for(i = start; i <= end; i++)
        aPtr[i] = temp[i-start];

        // merge first attempt
    /*
    int size1 = middle - start + 1;
    int size2 = end - middle;

    int left[size1];
    int right[size2];

    for(int i = 0; i < size1; i++)
        left[i] = aPtr[start + i];
    for(int i = 0; i < size2; i++)
        right[i] = aPtr[middle + 1 + i];

    //then merge them back
    int leftindex = 0;
    int rightindex = 0;
    int mergedindex = start;

    while(leftindex < size1 && rightindex < size2){
        if(left[leftindex] <= right[rightindex]) { //left object should go in first
            aPtr[mergedindex] = left[leftindex];
            leftindex++;
        }
        else {
            aPtr[mergedindex] = right[rightindex];
            rightindex++;
        }
        mergedindex++;
    }

    //then deal with the leftovers (if there are any)
    while(leftindex < size1) {
        aPtr[mergedindex] = left[leftindex];
        leftindex++;
        mergedindex++;
    }

    while(rightindex < size2) {
        aPtr[mergedindex] = right[rightindex];
        rightindex++;
        mergedindex++;
    }
    */
   //cout << "through merging" << endl;
}


//display the list
void OrderedList::display() {
    // cout << "There are: " << count << " Nodes in the list." << endl;
    cout << "OrderedList Display: " << endl;
    
    for(int i = 0; i < count; i++)
        cout << aPtr[i] << " ";

    cout << endl;

   // cout << "Head is pointing at the num: " << head->num << endl;
   // cout << "Tail is pointing at the num: " << tail->num << endl;

   // cout << "out of while loop" << endl;
}

//return number of traversals
unsigned OrderedList::get_traversal() {
    return traversal;
}

int OrderedList::get_count() {
    return count;
}

#endif