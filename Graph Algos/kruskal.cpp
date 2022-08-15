#include "bits/stdc++.h"
using namespace std;
bool cmp(vector<int> &a, vector<int> &b){
    return a[2]<b[2];
}
void makeset(vector<int> &parent, vector<int> &rank, int n){
    for(int i=0;i<n;i++){
        parent[i]=i;
        rank[i]=0;
    }
}
int findParent(vector<int> &parent, int node){
    if(parent[node]==node){
        return node;
    }
    return parent[node]=findParent(parent,parent[node]);
}
void unionSet(int u, int v, vector<int> &parent, vector<int> & rank){
    v=findParent(parent,v);
    u=findParent(parent,u);
    if(rank[v]>rank[u]){
        parent[u]=v;
    }
    else if(rank[u]> rank[v]){
        parent[v]=u;
    }
    else{
        parent[v]=u;
        rank[u]++;
    }
}

int mst(vector<vector<int>> edges, int n){
    sort(edges.begin(),edges.end(),cmp);
    vector<int> parent(n);
    vector<int> rank(n);
    makeset(parent,rank,n);
    int wt=0;
    for(int i=0; i<edges.size();i++){
        int u=findParent(parent,edges[i][0]);
        int v=findParent(parent,edges[i][1]);
        int nw=edges[i][2];
        if(u!=v){
            wt+=nw;
            unionSet(u,v,parent,rank);
        }
    }
    return wt;
}
int main(){
    vector<vector<int>> edges{{1,4,1},{1,2,2},{2,3,3},{2,4,3},{1,5,4},{3,4,5},{2,6,7},{3,6,8},{4,5,9}};
    int n=9;
    cout<<mst(edges,n);
}