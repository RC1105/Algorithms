#include "bits/stdc++.h"
using namespace std;
bool isPerfect(int no){
    int cnt=1;
    for(int i=2; i*i<=no;i++){
        if(no%i==0){    
            if(i/no == i){
                cnt+=i;
            }
            else{
                cnt+=i+no/i;
            }
        }
    }
    return cnt==no && no!=1;
}

int subarrayWithMaxPerf(vector<int> arr, int k){
    int res=0;
    for(int i=0;i<k;i++){
        res+=arr[i];
    }
    int sm=res;
    for(int i=k;i<arr.size();i++){
        sm+=arr[i]-arr[i-k];
        res=max(res,sm);
    }
    return res;
}

int MaxPerf(vector<int> arr, int k){
    for(int i=0; i<arr.size();i++){
        if(isPerfect(arr[i])){
            arr[i]=1;
        }
        else{
            arr[i]=0;
        }
    }
    for(int i=0; i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return subarrayWithMaxPerf(arr,k);
}

int main(){
    vector<int> vec{24,28,2,3,6,496,99,8128};
    int k=4;
    cout<<MaxPerf(vec,k);
}