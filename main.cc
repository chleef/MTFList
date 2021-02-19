#include "main.h"

//Driver
int main(int argc, const char * argv[]){
    try{
        LL List;
     
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
            List.push_front(hold);
        }


        cout << "List after Additions: ";
        List.display();
        cout << endl;
      //  cout << "Back in main" << endl;

        File >> count;
        for(int i = 0; i < count; i++) {
            File >> hold;
            List.search(hold);
        }

        cout << "List after Queries: ";
        List.display();
        cout << endl;
        cout << "Traversal Count: " << List.get_traversal() << endl;

        File.close();
    }
    catch(exception &e) {
        cout << "Exception caught in main: " << e.what() << endl;
    }

 //   cout << "made it to the end of main" << endl;
    return 0;
}