#include "bits/stdc++.h"
using namespace std;
bool hasRP(string s){
    stack<char> st;
    bool ans=false;
    for(int i=0; i<s.size();i++){
        
        char ch=s[i];
        if(ch=='(' || ch=='+' || ch=='-' || ch=='/' || ch=='*'){
            st.push(ch);
        }
        else{
            ans=true;
            if(ch==')'){
                while(!st.empty() && st.top()!='('){
                    char c=st.top();
                    if(c=='+' || c=='-' || c=='*' || c=='/'){
                        ans=false;
                    }
                    st.pop();
                }
            }
        }
    }
    return ans;
}
int main(){
    string s="(a+b)";
    cout<<hasRP(s);
}