#include <iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>,
rb_tree_tag, tree_order_statistics_node_update>;
// int summation(int x,int n){
//     int sum=0;
//     for(int i=x;i<=n;i+=x){
//         sum+=i;
//     }
//     return sum;
// }
#define M 1000000007
 
// Mathematical functions
class DSU
{

public:
    vector<int> par, size;
 
    DSU(int n = 0)
    {
        par.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            par[i] = i;
    }
 
    int findPar(int node)
    {
        if (node == par[node])
            return node;
        return par[node] = findPar(par[node]); // path comp
    }
 
    void unionbySize(int u, int v)
    {
        int UparU = findPar(u);
        int UparV = findPar(v);
        if (UparU == UparV)
            return;
        if (size[UparU] < size[UparV])
        {
            par[UparU] = UparV;
            size[UparV] += size[UparU];
        }
        else
        {
            par[UparV] = UparU;
            size[UparU] += size[UparV];
        }
    }
};
long long mod_sub(long long a, long long b, long long m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
long long powermod(long long x, long long y, long long p)
{
    long long res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
// struct comp {
//   bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
//     if (a.first != b.first) return a.first > b.first; // Changed for descending order
//     return a.second < b.second; // Ascending order for secondary sort
//   }
// };




vector<int> zAlgo(string s){
    //z[i] denotes that len of the largest substring starting from i that matches the prefix of s
    int left=0,right=0;
    int n= s.size();
    vector<int> z(n);
    z[0]=0;
    for(int k=1;k<n;k++){
        if(k>right){
            left=k,right=k;
            while(right<n && s[right]==s[right-left]){
                right++;
            }
            z[k]=right-left;
            right--;
        }
        else{
            //inside the window
            int k1=k-left;
            if(z[k1]<right-k+1){
                z[k]=z[k1];
            }
            else{
                left=k;
                while(right<n && s[right]==s[right-left]){
                    right++;
                }
                z[k]=right-left;
                right--;
            }
        }
    }
    return z;
}
int main(){
    string s;
    cin>>s;
    auto Z = zAlgo(s);
    int max_answer = 0;
    int max_zi = Z[1];
    for (int suffix = 2; suffix < s.length(); ++suffix) {
        // if [suffix, n-1] is possible
 
        if (Z[suffix] == 0)
            continue;
        int answer_len = s.length() - suffix;
        int available_z = max_zi;
        max_zi = max(max_zi, Z[suffix]);
        if (Z[suffix] != answer_len) continue;
        if (available_z >= answer_len) {
            max_answer = answer_len;
            break;
        }
    }
    if (max_answer > 0) {
        for(int i=0; i<max_answer; ++i)
            cout << s[i];
    } else {
        cout << "Just a legend";
    }
    return 0;
}