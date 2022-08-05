#include "bits/stdc++.h"
using namespace std;
int smallestWindow(vector<int> arr, int x){
    int n=arr.size();
    int sum=0, minLen=n+1, start=0, end=0;
    while(end<n){
        while(sum<=x && end<n){
            sum+=arr[end++];
        }
        while(sum> x && start<n){
            if(minLen> end-start){
                minLen=end-start;
            }
            
            sum-=arr[start++];
        }
    }
    if(minLen==n+1){
        return -1;
    }
    return minLen-1;
}
int main(){
    vector<int> arr{1,4,45,6,10,19};
    int x=51;
    cout<<smallestWindow(arr,x);
}