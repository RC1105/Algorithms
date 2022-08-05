#include "bits/stdc++.h"
using namespace std;
bool isPossible(vector<int> &arr, int k, int mid){
    int cowCnt=1;
    int last=arr[0];
    for(int i=0; i<arr.size();i++){
        if(arr[i]-last>=mid){
            cowCnt++;    
            if(cowCnt==k){
                return true;
            }
            last=arr[i];
        }
    }
    return false;
}
int aggCow(vector<int> & vec, int k){
    sort(vec.begin(),vec.end());
    int s=0;
    int maxx=vec[vec.size()-1];
    int e=maxx;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        if(isPossible(vec,k,mid)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
int main(){
    vector<int> vec{4,2,1,3,6};
    int k=2;
    cout<<aggCow(vec,k);
}