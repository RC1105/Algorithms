#include "bits/stdc++.h"
using namespace std;
int main(){
    vector<int> arr{12,-3,10,0};
    int n=arr.size();
    sort(arr.begin(),arr.end());
    int mn=0,mx=0;
    for(int i=0; i<n/2;i++){
        mx+=abs(arr[i+(n/2)]-arr[i]);
        mn+=abs(arr[2*i+1]-arr[2*i]);
    }
    cout<<mx<<" "<<mn;
}