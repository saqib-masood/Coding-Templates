#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    
   while(T){
      int ans;
      
    int n;
    cin>>n;
    int arr[n];
    int i=0;
    while(i<n){
        
        cin>>arr[i];
        i++;
    }
    sort(arr,arr+n);
    i=0;
    int duplicate=0;
   
   while(i+1<n){
       
       while(arr[i]==arr[i+1]){
           duplicate++;
           i++;
       }
       i++;
   }
   if(duplicate%2==1){
       duplicate=duplicate+1;
   }
   ans=n-duplicate;
   cout<<ans<<endl;


    T--;

   }
    
}