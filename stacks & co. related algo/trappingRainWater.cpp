#include "bits/stdc++.h"
using namespace std;
int trap(vector<int> vec){
    int n=vec.size();
    vector<int> left(n);
    vector<int> right(n);
    left[0]=vec[0];
    right[n-1]=vec[n-1];
    for(int i=1; i<n;i++){
        left[i]=max(left[i-1], vec[i]);
    }
    for(int j=n-2;j>=0;j--){
        right[j]=max(right[j+1],vec[j]);
    }
    int ans=0;
    for(int i=0; i<n;i++){
        ans+=min(right[i],left[i])-vec[i];
    }
    return ans;
    
}
int main(){
    vector<int> vec={3,1,2,4,0,1,3,2};
    cout<<trap(vec);
}