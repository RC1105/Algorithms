#include "bits/stdc++.h"
using namespace std;

void dfs(int node, unordered_map<int,bool> &vis, stack<int> &st, unordered_map<int,list<int>>&adj){
    vis[node]=true;
    for(auto neigh: adj[node]){
        if(!vis[neigh]){
            dfs(neigh,vis,st,adj);
        }
    }
    st.push(node);
}
void revDfs(int node,unordered_map<int,bool> &vis, stack<int> &st, unordered_map<int,list<int>>&adj){
    vis[node]=true;
    for(auto neigh: adj[node]){
        if(!vis[neigh]){
            revDfs(neigh,vis,st,adj);
        }
    }
}
int stronglyCC(int v, vector<vector<int>> &edges){
    unordered_map<int,list<int>> adj;
    for(int i=0; i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    stack<int> st;
    unordered_map<int,bool> vis;
    for(int i=0; i<v;i++){
        if(!vis[i]){
            dfs(i,vis,st,adj);
        }
    }
    unordered_map<int,list<int>> transpose;
    for(int i=0; i<v;i++){
        vis[i]=0;
        for(auto neigh: adj[i]){
            transpose[neigh].push_back(i);
        }
    }
    int cnt=0;
    while(!st.empty()){
        int top=st.top();
        st.pop();
        if(!vis[top]){
            cnt++;
            revDfs(top,vis,st,transpose);
        }
    }
    return cnt;
}
int main(){
    int v=5;
    vector<vector<int>> edges{{2,0},{0,1},{1,2},{1,3},{3,4}};
    cout<<stronglyCC(v,edges);
}