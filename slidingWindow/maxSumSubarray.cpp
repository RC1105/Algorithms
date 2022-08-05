#include "bits/stdc++.h"
using namespace std;

int printMaxSubarray(vector<int> arr, int x, int k){
    int sm=0;
    int ans=0;
    for(int i=0; i<k;i++){
        sm+=arr[i];
    }
    if(sm< x){
        ans=sm;
    }
    for(int i=k;i<arr.size();i++){
        sm+=arr[i];
        sm-=arr[i-k];
        if(sm>ans && sm<x){
            ans=sm;
        }
    }
    return ans;
}

int main(){
    vector<int> arr{7,5,4,6,8,9};
    int x=20;
    int k=3;
    cout<<printMaxSubarray(arr,x,k);
}