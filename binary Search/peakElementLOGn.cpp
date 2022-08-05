#include "bits/stdc++.h"
using namespace std;

int peakElement(vector<int> arr, int low, int high,int n){
    int mid=(low+high)/2;
    if( (mid==0 || arr[mid-1]< arr[mid]) && (mid+1==n ||arr[mid]>arr[mid+1]) ){
        return mid;
    }
    if(mid>0 && arr[mid]> arr[mid-1]){
        return peakElement(arr,mid+1,high,n);
    }
    return peakElement(arr,mid+1,high,n);
}
int peakElement2(vector<int>arr, int n){
    int s=0;
    int e=n-1;
    int m=s+(e-s)/2;
    while(s<e){
        if(arr[m]<arr[m+1]){
            s=m+1;
        }
        else{
            e=m;
        }
        m=s+(e-s)/2;
    }
    return s;
}

int main(){
    vector<int> arr{1,2,3,4,7,2};
    cout<<peakElement(arr,0,arr.size()-1,arr.size());
    cout<<peakElement2(arr,arr.size());
}