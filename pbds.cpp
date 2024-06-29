#include <iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less_equal<T>,
rb_tree_tag, tree_order_statistics_node_update>;
//Ques: Given q queries of 
//type 1 x: insert x
//type 2 x: give the xth smallest element
//type 3 x: print the number of elements less than x
//Constraints: 1<=q<=10^6, 1<=x<=10^9
//sample TC if 0 based indexing
// 7
// 1 1
// 1 2
// 1 4
// 2 1  --> 2
// 1 8
// 1 16
// 3 4 ---> 2
int main(){
    oset<int> s;
    int q;
    cin>>q;
    while(q--){
        int type,x;
        cin>>type>>x;
        if(type==1){
            //log(n)
            s.insert(x);
        }
        else if(type==2){
            //log(n)
            cout<<*s.find_by_order(x)<<endl;
        }
        else{
            //log(n)
            cout<<s.order_of_key(x)<<endl;
        }
    }
}