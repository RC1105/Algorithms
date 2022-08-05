#include "bits/stdc++.h"
using namespace std;
int main(){

    vector<int> vec{5,2,4,7};
    priority_queue <int, vector<int>, greater<int> > pq;
    for(int i=0; i<vec.size();i++){
        pq.push(vec[i]);
    }
    int ans=0;
    while(pq.size()!=1){
        int r=pq.top();
        pq.pop();
        int s=pq.top();
        pq.pop();
        ans=ans+r+s;
        pq.push(r+s);
    }
    cout<<ans;
}