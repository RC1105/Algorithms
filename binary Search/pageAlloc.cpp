#include "bits/stdc++.h"
using namespace std;
bool isPossible(vector<int> arr, int m, int n, int mid){
    int students=1;
    int pageSum=0;
    for(int i=0;i<n;i++){
        if(pageSum+arr[i]<=mid){
            pageSum+=arr[i];
        }
        else{
            students++;
            if(students>m || arr[i]>mid){
                return false;
            }
            pageSum=0;
            pageSum+=arr[i];
        }
    }
    return true;
}
int pgAlloc(vector<int> arr, int m, int n){
    int sm=0;
    for(int i=0; i<n;i++){
        sm+=arr[i];
    }
    int s=0;
    int e=sm;
    int ans=-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(isPossible(arr,m,n,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
int main(){
    vector<int> arr={10,20,30,40};
    int m=2;
    int n=arr.size();
    cout<<pgAlloc(arr,m,n);
}