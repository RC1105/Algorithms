#include "bits/stdc++.h"
using namespace std;
bool threeSum(vector<int> arr, int target){
    sort(arr.begin(),arr.end());
    bool ans=false;
    for(int i=0; i<arr.size();i++){
        int lo=i+1, hi=arr.size()-1;
        while(lo<hi){        
            int sum=arr[i]+arr[lo]+arr[hi];
            if(sum==target){
                return true;
            }
            else if(sum>target){
                hi--;
            }
            else{
                lo++;
            }
        }

    }
    return ans;
}
int main(){
    vector<int> arr{12,3,6,7,1,9};
    cout<<threeSum(arr,24);
}