#include <fstream>
#include <iostream>
#include "TopCommonWords.h"

using namespace std;

int main(int argc,char** argv){
    if(argc<2){
        cout<<"Usage: ./TopCommonWords path_to_file [num_words_to_find]"<<endl;
        return 0;
    }
    int n=10;
    if(argc>2){
        n=stoi(argv[2]);
    }
    ifstream in(argv[1]);
    map<string,int> m=countWords(in);
    vector<pair<int,vector<string>>> v=topWords(m,n);
    printTop(v,cout);
    return 0;
}
