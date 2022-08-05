#include "bits/stdc++.h"
using namespace std;


void sortedInsert(stack<int> &st, int val){
    if(st.empty() || !st.empty() && st.top()<val){
        st.push(val);
        return;
    }
    int curr=st.top();
    st.pop();
    sortedInsert(st,val);
    st.push(curr);
}
void sortSt(stack<int> &st){
    if(st.empty()){
        return;
    }
    int curr=st.top();
    st.pop();
    sortSt(st);
    sortedInsert(st,curr);
}

int main(){
    stack<int> st;
    st.push(7);
    st.push(4);
    st.push(2);
    st.push(20);
    st.push(1);
    st.push(3);
    sortSt(st);
    cout<<st.top();
}