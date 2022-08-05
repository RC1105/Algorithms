#include "bits/stdc++.h"
using namespace std;
int ceil(vector<int> arr, int target){
    int s=0;
    int ans=-1;
    int e=arr.size()-1;
    int mid=0;
    while(s<=e){
        mid=s+(e-s)/2;
        if(arr[mid]==target){
            e=mid-1;
        }
        else if(arr[mid]<target){
            ans=arr[mid];
            s=mid+1;
        }
        else if(arr[mid]>target){
            
            e=mid-1;
        }
    }
    return ans;

}
int main(){
    vector<int> arr{1,2,4,5,8,14,17};
    cout<<ceil(arr,1);
}