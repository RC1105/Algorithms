#include "bits/stdc++.h"
using namespace std;
int pivot(vector<int> vec){
    int n=vec.size();
    int s=0;
    int e=n-1;
    while(s<e){
        int mid=s+(e-s)/2;
        if(vec[mid]>=vec[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
    }
    return e;
}
int main(){
    vector<int> arr{7,8,9,1,2,3};
    cout<<pivot(arr);
}