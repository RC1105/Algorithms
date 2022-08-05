#include "bits/stdc++.h"
using namespace std;
bool isSafe(int newx, int newy,vector<vector<int>>& arr, int n,vector<vector<bool>> &vis, string path ){
    if(newx>=0 && newy>=0 && newx<=n-1 && newy<=n-1 && vis[newx][newy]!=1 && arr[newx][newy]==1){
        return true;
    }
    return false;
}
void solveMaze(int x,int y,vector<vector<int>>& arr, int n, vector<string> &ans,vector<vector<bool>> &vis, string path){
    if(x==n-1 && y==n-1){
        ans.push_back(path);
        return;
    }
    vis[x][y]=1;
    if(isSafe(x+1,y,arr,n,vis,path)){
        solveMaze(x+1,y,arr,n,ans,vis,path+'D');
    }
    if(isSafe(x,y+1,arr,n,vis,path)){
        solveMaze(x,y+1,arr,n,ans,vis,path+'R');
    }
    if(isSafe(x-1,y,arr,n,vis,path)){
        solveMaze(x-1,y,arr,n,ans,vis,path+'U');
    }
    vis[x][y]=0;
}
vector<string> solveUtil(vector<vector<int>> & maze, int N){
    vector<vector<bool>> vis(N,vector<bool>(N,false));
    vector<string> ans;
    if(maze[0][0]==0){
        return ans;
    }
    string path="";
    solveMaze(0,0,maze,N,ans,vis,path);
    return ans;
}
int main(){
    int N=4;
    vector<vector<int>> maze {{ 1, 0, 0, 0 },{ 1, 1, 0, 1 },{ 0, 1, 0, 0 },{ 1, 1, 1, 1 } };
    vector<string> ans=solveUtil(maze,N);
    for(int i=0; i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}