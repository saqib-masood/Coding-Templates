#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define ll long long

using namespace std;
//String : a a b a a # a a b a a d
//LPS :    0 1 0 1 2 0 1 2 3 4 5 0
//LPS=Largest Prefix that matches Suffix

vector<int> kmp(string pattern,string str){
    string s=pattern+"#"+str;
    
    vector<int> lps(s.size(),0);
    for(int i=1;i<s.size();i++){
        int prevLps=lps[i-1];
        while(prevLps>0 && s[i]!=s[prevLps]){
            prevLps=lps[prevLps-1];
        }
        lps[i]=prevLps+(s[i]==s[prevLps]);
    }
    return lps;
}
int main(){
    vector<int> v=kmp("aabaa","aabaaabaa");
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}