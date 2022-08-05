#include "bits/stdc++.h"
using namespace std;
int larRect(vector<int> arr){
    int ans=0;
    for (int i=0; i<arr.size();i++){
        int minh=INT_MAX;
        for(int j=i; j<arr.size();j++){
            minh=min(minh,arr[j]);
            int b=j-i+1;
            ans=max(ans,minh*b);
        }   
    }
    return ans;
}
int main(){
    vector<int> arr{2,1,5,6,2,3};
    cout<<larRect(arr);  
}