#include "main.h"

//Driver
int main(int argc, const char * argv[]){
    try{
        LL MTFList;
        OrderedList OList;

        ifstream File;
        ifstream File2;
        //File.open("P1a_TestFile.txt");
        
        if(argc < 2)
            cout << "not enough arguments" << endl;
        File.open(argv[1]);
        File2.open(argv[1]);
        
        int count;
        File >> count;
        int hold;
        for(int i = 0; i < count; i++) {
            File >> hold;
            OList.push_back(hold);
        }

        int count2;
        File2 >> count2;
        int hold2;
        for(int i = 0; i < count2; i++) {
            File2 >> hold2;
            MTFList.push_front(hold2);
        }


      //  cout << "Lists after Additions: " << endl;
      //  MTFList.display();
        cout << endl;
      //  OList.display();
        cout << endl;
       // cout << "Back in main" << endl;

        auto start1 = chrono::steady_clock::now();

        OList.merge_sort(0, OList.get_count()-1);

        
        File >> count;
        for(int i = 0; i < count; i++) {
            File >> hold;
            OList.bi_search(0, OList.get_count()-1,hold);
        }

        auto end1  = chrono::steady_clock::now();

        auto start2 = chrono::steady_clock::now();

        File2 >> count2;
        for(int i = 0; i < count2; i++) {
            File2 >> hold2;
            MTFList.search(hold2);
        }

        auto end2 = chrono::steady_clock::now();


        cout << "OrderedList time (in ns) to merge sort and search: " << chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count() << endl;
        cout << "MTFList time (in ns) to search: " << chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count() << endl;

        if(end1 - start1 < end2 - start2)
            cout << "ordered list is faster" << endl;
        else
            cout << "MTF list is faster" << endl;
      //  cout << "Post merge sort: " << endl;

       // OList.display();
        cout << endl;


        cout << "List after Queries: " << endl;
       // MTFList.display();
        cout << endl;
        cout << "MTFList Traversal Count: " << MTFList.get_traversal() << endl;
        cout << "OrderedList Traversal Count: " << OList.get_traversal() << endl;

        File.close();
       // cout << "made it past file close" << endl;
    }
    catch(exception &e) {
        cout << "Exception caught in main: " << e.what() << endl;
    }

   // cout << "made it to the end of main" << endl;
    return 0;
}