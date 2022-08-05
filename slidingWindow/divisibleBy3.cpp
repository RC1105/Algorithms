#include "bits/stdc++.h"
using namespace std;
void computeIt(vector<int> arr, int k){
    int sm=0;
    bool found=false;
    pair<int,int> ans;
    for(int i=0; i<k;i++){
        sm+=arr[i];
    }
    if(sm%3==0){
        found=true;
        ans=make_pair(0,k-1);
    }
    for(int i=k;i<arr.size();i++){
        if(found){
            break;
        }
        sm+=arr[i];
        sm-=arr[i-k];
        if(sm%3==0){
            found=true;
            ans=make_pair(i-k+1,i);
        }
    }
    if(!found){
        make_pair(-1,0);
    }
    if(ans.first==-1){
        cout<<"NO SUBARRAY FOUND";
    }
    for(int i=ans.first;i<=ans.second;i++){
        cout<<arr[i]<<" ";
    }

}
int main(){
    vector<int> arr{84,23,34,12,56,82};
    int k=3;
    computeIt(arr,k);
}