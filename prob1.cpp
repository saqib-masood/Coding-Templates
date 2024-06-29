#include <iostream>
using namespace std;
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans=n-1;
        int a=1,b=n-1;
        int A=1,B=n-1;
        while(a<b){
            a++;
            b--;
            // ans = min(ans,lcm(a,b));
            int l=lcm(a,b);
            if(l<ans){
                ans = l;
                A=a;
                B=b;
            }
        }
        cout<<A<<" "<<B<<"\n";
    }
    
    return 0;
}