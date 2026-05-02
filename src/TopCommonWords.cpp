#include "TopCommonWords.h"
#include <algorithm>
#include <cctype>

using namespace std;

string low(string s){
    for(char& c:s){
        c=tolower((unsigned char)c);
    }
    return s;
}

string cleanWord(const string& s){
    string t=low(s);
    int a=0;
    int b=(int)t.size()-1;
    while(a<(int)t.size()&&!isalnum((unsigned char)t[a])){
        a++;
    }
    while(b>=a&&!isalnum((unsigned char)t[b])){
        b--;
    }
    if(a>b){
        return "";
    }
    return t.substr(a,b-a+1);
}

bool skipWord(const string& s){
    return s=="a"||s=="an"||s=="and"||s=="in"||s=="is"||s=="it"||s=="the";
}

string showWords(const vector<string>& v){
    string s="{";
    for(int i=0;i<(int)v.size();i++){
        s+=v[i];
        if(i<(int)v.size()-1){
            s+=", ";
        }
    }
    s+="}";
    return s;
}
