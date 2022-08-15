#include "bits/stdc++.h"
using namespace std;
int bellmanFord(int n , int m, int src, int des, vector<vector<int>> &edges){
   
   vector<int> dis(n,INT_MAX);
   dis[src]=0;
    for(int i=1; i<=n;i++){
        for(int j=0; j<m;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int wt=edges[j][2];
            if(dis[u]!=INT_MAX && dis[v]> dis[u]+wt){
                dis[v]=dis[u]+wt;
            }
        }
    }
    bool flag=false;
    for(int j=0; j<m;j++){
        int u=edges[j][0];
        int v=edges[j][1];
        int wt=edges[j][2];
        if(dis[u]!=INT_MAX && dis[v]> dis[u]+wt){
            flag==true;
        }
    }
    if(flag){
        return -1;
    }
    return dis[des];
}
int main(){
    int n=3;
    int m=3;
    vector<vector<int>> edges{{1,2,2},{2,3,-1},{3,1,2}};
    cout<<bellmanFord(n,m,1,3,edges);
}