#include "bits/stdc++.h"
using namespace std;
int main(){
    int n=390;
    int ans=0;
    vector<int> arr{1,50,2,5,100,200,10,20,2000};
    sort(arr.begin(),arr.end(),greater<int>());
    for(int i=0; i<arr.size();i++){
        ans=ans+(n/arr[i]);
        n=n-(n/arr[i])*arr[i];
    }
    cout<<ans;
}