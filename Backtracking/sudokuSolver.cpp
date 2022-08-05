#include "bits/stdc++.h"
using namespace std;

bool isSafe(vector<vector<char>> &vec, int row, int col, char c){
    for(int i=0; i<vec.size();i++){
        if(vec[row][i]==c){
            return false;
        }
        if(vec[i][col]==c){
            return false;
        }
        if(vec[3*(row/3) + (i/3)][3*(col/3) + (i%3)]==c){
            return false;
        }
    }
    return true;
}
bool sudsolve(vector<vector<char>> &vec){
    for(int i=0; i<vec.size();i++){
        for(int j=0; j<vec[i].size();j++){
            if(vec[i][j]=='0'){
                for(char c='1'; c<='9';c++){
                    if(isSafe(vec,i,j,c)){
                        vec[i][j]=c;
                        if(sudsolve(vec)==true){
                            return true;
                        }
                        else{
                            vec[i][j]='0';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solve(vector<vector<char>> &vec){
    sudsolve(vec);
}
int main(){
    vector<vector<char>> vec{ {'3', '0', '6', '5', '0', '8', '4', '0', '0'}, 
         {'5', '2', '0', '0', '0', '0', '0', '0', '0'}, 
         {'0', '8', '7', '0', '0', '0', '0', '3', '1'}, 
         {'0', '0', '3', '0', '1', '0', '0', '8', '0'}, 
         {'9', '0', '0', '8', '6', '3', '0', '0', '5'}, 
         {'0', '5', '0', '0', '9', '0', '6', '0', '0'}, 
         {'1', '3', '0', '0', '0', '0', '2', '5', '0'}, 
         {'0', '0', '0', '0', '0', '0', '0', '7', '4'}, 
         {'0', '0', '5', '2', '0', '6', '3', '0', '0'} };
    solve(vec);
    for(int i=0; i<9;i++){
        for(int j=0; j<9;j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
}