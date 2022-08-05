#include "bits/stdc++.h"
using namespace std;
void slide(vector<int> vec, int k){
    deque<int> dq;
    vector<int> ans;
    for(int i=0; i<vec.size();i++){
        if(!dq.empty() && dq.front()<=i-k ){
            dq.pop_front();
        }
        while(!dq.empty() && vec[dq.back()]<vec[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=k-1){
            ans.push_back(vec[dq.front()]);
        }
    }
    for(int i=0; i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
int main(){
    vector<int> arr{4,1,3,5,1,2,3,2,1,1,5};
    int k=3;
    slide(arr,k);
}