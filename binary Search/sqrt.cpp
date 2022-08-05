#include "bits/stdc++.h"
using namespace std;
long long int sqrt(int n){
    int s=0;
    int e=n;
    long long int mid=s+(e-s)/2;
    long long int ans=-1;
    while(s<=e){
        long long int sq=mid*mid;
        if(sq==n){
            return mid;
        }
        if(sq<n){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

double prec(int n,long long int tempSol, int precision){
    double factor=1;
    double ans=tempSol;
    for(int i=0; i<precision;i++){
        factor=factor/10;
        for(double j=ans; j*j<n;j+=factor){
            ans=j;
        }
    }
    return ans;
}
int main(){
    long long int ans=sqrt(3);
    cout<<prec(3,ans,3);
    cout<<ans;
}