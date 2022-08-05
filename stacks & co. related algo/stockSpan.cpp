#include "bits/stdc++.h"
using namespace std;
void stockSpan(vector<int> vec){
    stack<pair<int,int>> st;
    vector<int> ans(vec.size());
    for(int i=0; i<vec.size();i++){
        int days=1;
        while(!st.empty() && st.top().first <vec[i]){
            days+=st.top().second;
            st.pop();
        }
        st.push({vec[i],days});
        ans[i]=days;
    }
    for(int i=0; i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
int main(){
    vector<int> vec{100,80,60,70,60,75,85};
    stockSpan(vec);
}