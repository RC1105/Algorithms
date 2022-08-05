#include "bits/stdc++.h"
using namespace std;
bool isSafe(int row,int col,vector<string> &board,int n){
    int temprow=row;
    int tempcol=col;
    while(row>=0 && col>=0){
        if(board[row][col]=='Q'){
            return false;
        }
        row--;
        col--;
    }
    row=temprow;
    col=tempcol;
    while(col>=0){
        if(board[row][col]=='Q'){
            return false;
        }
        col--;
    }
    row=temprow;
    col=tempcol;
    while(col>=0 && row<n){
        if(board[row][col]=='Q'){
            return false;
        }
        col--;
        row++;
    }
    return true;
}
void solve(int col,vector<string> &board,vector<vector<string>> &ans,int n){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int row=0; row<n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col]='Q';
            solve(col+1,board,ans,n);
            board[row][col]='.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n,'.');
    for(int i=0; i<n;i++){
        board[i]=s;
    }
    solve(0,board,ans,n);
    return ans;    
}
int main(){
    int n=4;
    vector<vector<string>> ans;
    ans=solveNQueens(n);
    for(int i=0; i<ans.size();i++){
        for(int j=0; j<ans[i].size();j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
}