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

map<string,int> countWords(istream& in){
    map<string,int> m;
    string s;
    while(in>>s){
        string t=cleanWord(s);
        if(t==""||skipWord(t)){
            continue;
        }
        m[t]++;
    }
    return m;
}

bool cmp(const pair<string,int>& a,const pair<string,int>& b){
    if(a.second!=b.second){
        return a.second>b.second;
    }
    return a.first<b.first;
}

vector<pair<int,vector<string>>> topWords(const map<string,int>& m,int n){
    vector<pair<string,int>> v;
    for(auto p:m){
        v.push_back(p);
    }
    sort(v.begin(),v.end(),cmp);
    vector<pair<int,vector<string>>> ans;
    int used=0;
    int i=0;
    while(i<(int)v.size()&&used<n){
        int c=v[i].second;
        vector<string> words;
        while(i<(int)v.size()&&v[i].second==c){
            words.push_back(v[i].first);
            i++;
        }
        ans.push_back({c,words});
        used+=words.size();
    }
    return ans;
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

void printTop(const vector<pair<int,vector<string>>>& v,ostream& out){
    for(int i=0;i<(int)v.size();i++){
        out<<i+1<<".) These words appeared "<<v[i].first<<" times: "<<showWords(v[i].second)<<endl;
    }
}
