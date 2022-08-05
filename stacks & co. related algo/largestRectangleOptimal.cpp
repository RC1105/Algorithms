#include "bits/stdc++.h"
using namespace std;

vector<int> nextSmallerElement(vector<int>& h, int n){
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);
    for(int i=n-1; i>=0; i--){
        int curr=h[i];
        while(st.top()!=-1 && curr<= h[st.top()]){
            st.pop();
        }
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int>& h, int n){
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        while(st.top()!=-1 && h[st.top()]>=h[i]){
            st.pop();
        }
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
    
}
int larRect(vector<int>& h){
    int n=h.size();
    vector<int> next;
    vector<int> prev;
    next=nextSmallerElement(h,n);
    prev=prevSmallerElement(h,n);
    int ans=INT_MIN;
    for(int i=0; i<n;i++){
        int l=h[i];
        if(next[i]==-1){
            next[i]=n;
        }
        int b=next[i]-prev[i]-1;
        int maxArea=l*b;
        ans=max(ans,maxArea);
    }
    return ans;
}
int main(){
    vector<int> arr{2,1,5,6,2,3};
    cout<<larRect(arr);  
}