#include<bits/stdc++.h>
using namespace std;
vector<int> zAlgo(string s){
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
    auto v=zAlgo("abaxabab");
    for(int i=0;i<8;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}