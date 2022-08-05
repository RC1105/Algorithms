#include "bits/stdc++.h"
using namespace std;
int maxUniqueSubs(string str){
    vector<int> mpp(256,-1);
    int l=0;
    int r=0,len=0;
    while(r<str.size()){
        if(mpp[str[r]]!=-1){
            l=max(l,mpp[str[r]]+1);
        }
        mpp[str[r]]=r;
        len=max(len,r-l+1);
        r++;
    }
    return len;
}
int main(){
    string str="abcdefabc";
    cout<<maxUniqueSubs(str);
}