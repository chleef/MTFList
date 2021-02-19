#include "main.h"

//Driver
int main(int argc, const char * argv[]){
    try{
        LL MTFList;
        OrderedList OList;
     
        ifstream File;
        //File.open("P1a_TestFile.txt");
        
        if(argc < 2)
            cout << "not enough arguments" << endl;
        File.open(argv[1]);
        
        int count;
        File >> count;
        int hold;
        for(int i = 0; i < count; i++) {
            File >> hold;
            MTFList.push_front(hold);
            OList.push_front(hold);
        }


        cout << "Lists after Additions: " << endl;
        MTFList.display();
        OList.display();
        cout << endl;
      //  cout << "Back in main" << endl;

        OList.merge_sort(OList.get_headPtr());

        cout << "Post merge sort: " << endl;

        OList.display();

        File >> count;
        for(int i = 0; i < count; i++) {
            File >> hold;
            MTFList.search(hold);
            OList.bi_search(OList.get_head(),hold);
        }

        cout << "List after Queries: " << endl;
        MTFList.display();
        cout << endl;
        cout << "MTFList Traversal Count: " << MTFList.get_traversal() << endl;
        cout << "OrderedList Traversal Count: " << OList.get_traversal() << endl;

        File.close();
    }
    catch(exception &e) {
        cout << "Exception caught in main: " << e.what() << endl;
    }

 //   cout << "made it to the end of main" << endl;
    return 0;
}