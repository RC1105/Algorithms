#include "bits/stdc++.h"
using namespace std;

vector<pair<pair<int,int>,int>> calcPrim(int n,int m, vector<vector<int>> &vec){
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0; i<m;i++){
        int u=vec[i][0];
        int w=vec[i][1];
        int p=vec[i][2];
        adj[u].push_back(make_pair(w,p));
        adj[w].push_back(make_pair(u,p));
    }
    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);
    for(int i=0; i<n+1;i++){
        key[i]=INT_MAX;
        parent[i]=-1;
        mst[i]=false;
    }
    key[1]=0;
    parent[1]=-1;
    for(int i=1; i<n;i++){
        int minn=INT_MAX;
        int u;
        for(int v=1;v<=n;v++){
            if(mst[v]==false && key[v]<minn){
                u=v;
                minn=key[v];
            }
        }
        mst[u]=true;
        for(auto itr:adj[u]){
            int v=itr.first;
            int w=itr.second;
            if(mst[v]==false && w<key[v]){
                parent[v]=u;
                key[v]=w;
            }
        }
    }
    vector<pair<pair<int,int>,int>> res;
    for(int i=2; i<=n;i++){
        //cout<<parent[i]<<" "<<i<<" "<<key[i]<<endl;
        res.push_back(make_pair({parent[i],i},key[i]));
    }
    for(int i=0; i<res.size();i++){
        cout<<res[i].first.first<<" "<<res[i].first.second<<" "<<res[i].second<<endl;
        
    }
    return res;
}
int main(){
    vector<vector<int>> vec{{0,1,2},{1,2,3},{2,4,7},{4,1,5},{1,3,8},{3,0,6}};
    vector<pair<pair<int,int>,int>> res=calcPrim(5,6,vec);
}