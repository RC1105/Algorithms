#include "bits/stdc++.h"
using namespace std;

int cp(vector<int> arr){
    int s=0;
    int ans=-1;
    int e=arr.size()-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]>=0){
            ans=mid;
            s=mid+1;
        }
        else if(arr[mid]<0){
            e=mid-1;
        }
    }
    return ans+1;
}
int main(){
    vector<int> arr{4,3,2,-1,-1};
    cout<<cp(arr);
}