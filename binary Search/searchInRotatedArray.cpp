#include "bits/stdc++.h"
using namespace std;
int searchInRotatedArray(vector<int> arr, int left, int right, int key){
    if(right<left){
        return -1;
    }
    int mid=(right+left)/2;
    if(arr[mid]==key){
        return mid;
    }
    if(arr[left]<=arr[mid]){//sorted Left
        if(key>=arr[left] && key<=arr[mid])
            return searchInRotatedArray(arr,left,mid-1,key);
        return searchInRotatedArray(arr,mid+1,right,key);
    }
    if(key>=arr[mid] && key<=arr[right]){
        return searchInRotatedArray(arr,mid+1,right,key);
    }
    return searchInRotatedArray(arr,left,mid-1,key);
}
int main(){
    vector<int> arr{1,2,3,4,0,7,8};
    cout<<searchInRotatedArray(arr,0,arr.size()-1,0);
}