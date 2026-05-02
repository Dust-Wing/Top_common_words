#include <fstream>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
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
    map<string,int> m;
    string s;
    while(in>>s){
        s=cleanWord(s);
        if(s==""||skipWord(s)){
            continue;
        }
        m[s]++;
    }
    vector<pair<string,int>> v;
    for(auto p:m){
        v.push_back(p);
    }
    sort(v.begin(),v.end(),[](const pair<string,int>& a,const pair<string,int>& b){
        if(a.second!=b.second){
            return a.second>b.second;
        }
        return a.first<b.first;
    });
    int used=0;
    int row=1;
    int i=0;
    while(i<(int)v.size()&&used<n){
        int c=v[i].second;
        vector<string> words;
        while(i<(int)v.size()&&v[i].second==c){
            words.push_back(v[i].first);
            i++;
        }
        cout<<row<<".) These words appeared "<<c<<" times: "<<showWords(words)<<endl;
        used+=words.size();
        row++;
    }
    return 0;
}
