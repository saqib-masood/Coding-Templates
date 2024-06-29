#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // int l=0,h=tasks.size();
        
        int m=tasks.size();
        vector<int> f(26,0);
        for(int i=0;i<m;i++){
            f[tasks[i]-'A']++;
        }
        int ans=0;
        
        set<pair<int,char>,greater<pair<int,char>>> s;
        for(int i=0;i<26;i++){
            s.insert({f[i],'A'+i});
        }
        vector<int> prev(26,-100);
        while(!s.empty()){
            auto it=s.begin();
            for(;it!=s.end();it++){
                auto curr=*it;
                int freq=curr.first;
                char c=curr.second;
                if(prev[c]+n<ans){
                    s.erase(curr);
                    if(freq-1>0){
                        s.insert({freq-1,c});
                    }
                    prev[c]=ans;
                    ans++;
                }
            }
            if(it==s.end()){
                ans++;
            }
        }
        return ans+1;
    }
};
int main(){
    cout<<"Hello World";
    Solution s;
    vector<char> tasks={'A','A','A','B','B','B'};
    int n=3;
    int ans=s.leastInterval(tasks,n);
    return 0;
 
}
 