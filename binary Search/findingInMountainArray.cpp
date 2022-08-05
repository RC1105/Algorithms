#include "bits/stdc++.h"
using namespace std;
int pivot(vector<int> arr){
    int s=0;
    int e=arr.size()-1;
    while(s<e){
        int mid=s+(e-s)/2;
        if(arr[mid]<arr[mid+1]){
            s=mid+1;
        }
        else{
            e=mid;
        }
    }
    return s;
}

int binSearch(vector<int> arr, int target, int s, int e){
    
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return -1;
}
int binSearch2(vector<int> arr, int target, int s, int e){
    
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return -1;
}
int findit(vector<int> arr,int target, int k){
    if(binSearch(arr,target,0,k)!=-1){
        return binSearch(arr,target,0,k);
    }
    else{
        return binSearch2(arr,target,k,arr.size());
    }
}
int main(){
    vector<int> arr{2,3,4,5,7,6,2,1,0};
    int k=pivot(arr);
    int target=0;
    cout<<findit(arr,target,k);
}