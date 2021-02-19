#include "main.h"

//Driver
int main(int argc, const char * argv[]){
    try{
        LL MTFList;
     
        ifstream File;
        //File.open("P1a_TestFile.txt");
        
        if(argc < 2)
            cout << "not enough arguments" << endl;
        File.open(argv[1]);
        
        int count;
        File >> count;
        OrderedList OList;
        int hold;
        for(int i = 0; i < count; i++) {
            File >> hold;
            MTFList.push_front(hold);
            OList.push_back(hold);
        }


        cout << "Lists after Additions: " << endl;
        MTFList.display();
        cout << endl;
        OList.display();
        cout << endl;
        cout << "Back in main" << endl;

        auto start = chrono::steady_clock::now();

        OList.merge_sort(0, OList.get_count()-1);

        auto end  = chrono::steady_clock::now();

        cout << "Time (in ns) to merge sort: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;

        cout << "Post merge sort: " << endl;

        OList.display();
        cout << endl;
        File >> count;
        for(int i = 0; i < count; i++) {
            File >> hold;
            MTFList.search(hold);
            OList.bi_search(0, OList.get_count()-1,hold);
        }

        cout << "List after Queries: " << endl;
        MTFList.display();
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