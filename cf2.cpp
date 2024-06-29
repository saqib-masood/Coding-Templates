#include <iostream>
#include <vector>
using namespace std;
#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
#define ll long long
// Function to calculate the digit sum of a number
int dp[101][101];
int solve(string a,string b,int i,int j){
    //a mei sbse bada subsequence jo match kre b se
    if(i==a.size() || j==b.size()){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int op1=0,op2=0,op3=0;
    if(a[i]==b[j]){
        op1=1+solve(a,b,i+1,j+1);
    }
    op2=solve(a,b,i+1,j);
    op3=solve(a,b,i,j+1);
    return dp[i][j]= max(op1,max(op2,op3));
}
int main() {
    int t;
    cin>>t;
    while(t--){
        string a,b;
        cin>>a>>b;
        memset(dp,-1,sizeof(dp));
        int m=a.size();
        int n=b.size();    
        int ans=m;
        ans+=n-solve(a,b,0,0);
        cout<<ans<<endl;
    }
    return 0;
}