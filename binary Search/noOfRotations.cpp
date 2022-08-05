#include "bits/stdc++.h"
using namespace std;
int pivot(vector<int> arr){
    int s=0;
    int e=arr.size()-1;
    while(s<e){
        int mid=s+(e-s)/2;
        if(arr[mid]>=arr[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
    }
    return s;
}
int Rotations(vector<int> arr){
    int k=pivot(arr);
    if(k==-1){
        return 0;
    }
    return k+1;
}
int main(){
    vector<int> arr{7,9,10,1,2,3};
    cout<<pivot(arr)<<endl;
    cout<<Rotations(arr);
}