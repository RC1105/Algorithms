#include "bits/stdc++.h"
using namespace std;

int search(vector<int> arr, int target,int s, int e){
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            e=mid-1;
        }
        else if(arr[mid]<target){
            s=mid+1;
        }
    }
    return -1;
}
int check(vector<int> arr, int target){
    int s=0;
    int e=1;
    while(arr[e]<target){
        int tmp=e+1;
        e=e+2*(e-s+1);
        s=tmp;
    }
    return search(arr,target,s,e);
}
int main(){
    vector<int> arr{1,2,3,4,5,6,7,8,11,14,15,17,19,22,27};
    int target=7;
    cout<<check(arr,target);
}