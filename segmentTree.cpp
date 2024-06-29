#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define ll long long

using namespace std;
class SegmentTree{
    public:
    vector<int> tree;
    vector<int> v;
    SegmentTree(vector<int> v){
        this->v=v;
        int n=v.size();
        tree.resize(4*n+1);
        buildSegmentTree(1,0,v.size()-1,v);
    }
    void buildSegmentTree(int node,int l,int h,vector<int> v){
        if(l==h){
            tree[node]=v[l];
            return;
        }
        int mid=l+(h-l)/2;
        buildSegmentTree(2*node,l,mid,v);
        buildSegmentTree(2*node+1,mid+1,h,v);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
    int Query(int node,int l,int h,int start,int end){
        int mid=l+(h-l)/2;
        //l-h
        //start-end
        int ans=0;
        if(l>end || h<start){
            return 0;
        }
        else if(l>=start && h<=end){
            return tree[node];
        }
        else{
            return Query(2*node,l,mid,start,end)+Query(2*node+1,mid+1,h,start,end);
        }
        
    }
    void Update(int ind,int val,int node,int start,int end){
        if(start==end){
            v[ind]=val;
            tree[node]=val;
            return;
        }
        int mid=(start+end)/2;
        if(ind<=mid){
            Update(ind,val,2*node,start,mid);
        }
        else{
            Update(ind,val,2*node+1,mid+1,end);
        }
        tree[node]=tree[2*node]+tree[2*node+1];
    }
    void update(int ind,int val){
        Update(ind,val,1,0,v.size()-1);
    }
    int query(int start,int end){
        return Query(1,0,v.size()-1,start,end);
    }
    void print(){
        for(int i=1;i<=tree.size();i++){
            cout<<tree[i]<<" ";
        }
    }
};
int main(){
    vector<int> v={5,3,2,4,1,8,6,10};
    SegmentTree s= SegmentTree(v);
    s.print();
    return 0;

}
