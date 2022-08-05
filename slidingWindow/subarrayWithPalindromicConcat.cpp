#include "bits/stdc++.h"
using namespace std;

int pali(int x){
    int tmp=x;
    int ans=0;
    while(tmp>0){
        ans=ans*10+tmp%10;
        tmp/=10;
    }
    return ans==x;
}
int palindromeSubs(vector<int> arr, int k){
    int sm=0;
    for(int i=0; i<k;i++){
        sm=sm*10+arr[i];
    }
    if(pali(sm)==1){
        return 0;
    }
    for(int i=k; i<arr.size();i++){
        int m=pow(10,k-1);
        sm=sm%m;
        sm=sm*10+arr[i];
        if(pali(sm)==1){
            return i-k+1;
        }
    }
    return -1;
}
int main(){
    vector<int> arr{2,3,5,1,1,5};
    int k=4;
    //cout<<pali(5115);
    cout<<palindromeSubs(arr,k);
}