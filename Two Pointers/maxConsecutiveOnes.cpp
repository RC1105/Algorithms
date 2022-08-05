#include "bits/stdc++.h"
using namespace std;
int maxConseq(vector<int> arr, int k){
    int zerocnt=0,i=0,ans=0;
    for(int j=0; j<arr.size();j++){
        if(arr[j]==0){
            zerocnt++;
        }
        while(zerocnt>k){
            if(arr[i]==0){
                zerocnt--;
            }
            i++;
        }
        ans=max(ans,j-i+1);
    }
    return ans;
}
int main(){
    vector<int> arr{1,1,1,0,0,0,1,1,1,1,0};
    int k=2;
    cout<<maxConseq(arr,k);
}