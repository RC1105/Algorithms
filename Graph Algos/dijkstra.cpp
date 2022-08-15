#include "bits/stdc++.h"
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int src){
    unordered_map<int, list<pair<int,int>>> adj;
    for(int i=0; i<edges;i++){
        int u=vec[i][0];
        int v=vec[i][1];
        int p=vec[i][2];
        adj[u].push_back(make_pair(v,p));
        adj[v].push_back(make_pair(u,p));
    }
    vector<int> dist(vertices);
    for(int i=0; i<dist.size();i++){
        dist[i]=INT_MAX;
    }
    set<pair<int,int>> st; //dist,node
    dist[src]=0;
    st.insert(make_pair(0,src));
    while(!st.empty()){
        auto top=*(st.begin());
        auto nodeDis=top.first;
        auto topNode=top.second;
        st.erase(st.begin());
        for(auto neigh: adj[topNode]){
            if(nodeDis+neigh.second<dist[neigh.first]){
                auto recc=st.find(make_pair(dist[neigh.first],neigh.first));
                if(recc!=st.end()){
                    st.erase(recc);
                }
                dist[neigh.first]=nodeDis+neigh.second;
                st.insert(make_pair(dist[neigh.first],neigh.first));
            }
        }
    }
    return dist;
}
int main(){
    vector<vector<int>> vec{{0,1,5},{0,2,8},{1,2,9},{1,3,2},{1,0,5},{2,0,8},{2,1,9},{2,3,6},{3,1,2},{3,2,6}};
    int vertices=4;
    int edges=5;
    int src=0;
    vector<int> ans=dijkstra(vec,vertices,edges,src);
    for(int i=0; i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}