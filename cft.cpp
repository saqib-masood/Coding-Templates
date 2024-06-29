#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y,z;
        ll k;
        cin>>x>>y>>z>>k;
        if(k>1ll*x*y*z){
            cout<<0<<endl;
            continue;
        }
        ll ans=0;
        for(int a=1;a<=x;a++){
            for(int b=1;b<=y;b++){
                int c=k/(a*b);
                if(z-c+1<=0 || c<=0 || c>z || 1ll*a*b*c!=k){
                    continue;
                }
                ll pos = 1ll*(x-a+1)*(y-b+1)*(z-c+1);
                ans=max(ans,pos);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}