#include "bits/stdc++.h"
using namespace std;

int main(){
    int n=3;
    int w=20;
    int val=0;
    vector<vector<int>> vec{{21,7},{24,4},{12,6},{40,5},{30,6}};
    for(int i=0; i<vec.size();i++){
        vec[i].push_back(double(vec[i][0])/double(vec[i][1]));
    }                                                                                           
    sort(vec.begin(),vec.end(),[&](vector<int> &a, vector<int> &b){
        return (a[2])>(b[2]);
    });
    for(int i=0; i<vec.size();i++){ 
        if(n<=0 || w<=0){
            break;
        }
        if(w>=vec[i][1]){
            w=w-vec[i][1];
            val+=vec[i][0];
            n--;
        }
        else{
            
            val+=vec[i][2]*w;
            w=0;
            n--;
        }
    }
    cout<<"The total points: "<<val;
}