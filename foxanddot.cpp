#include<bits/stdc++.h>
using namespace std;
bool dfs(int i,int j,int px,int py,vector<vector<bool>>&visited,vector<vector<char>>&grid,char ch){
    int n=grid.size();
    int m=grid[0].size();
   visited[i][j]=true;
   if(j+1<m&&grid[i][j+1]==ch){
    if(!(i==px&&j+1==py)){
    if(visited[i][j+1]){
        return true;
    }
        if(dfs(i,j+1,i,j,visited,grid,ch)){
            return true;
        }
    
}
}
if(i-1>=0&&grid[i-1][j]==ch){
    if(!(i-1==px&&j==py)){
    if(visited[i-1][j]){
        return true;
    }
        if(dfs(i-1,j,i,j,visited,grid,ch)){
            return true;
        }
   }
}
if(j-1>=0&&grid[i][j-1]==ch){
    if(!(i==px&&j-1==py)){
    if(visited[i][j-1]){
        return true;
    }
        if(dfs(i,j-1,i,j,visited,grid,ch)){
            return true;
        }
    
   }
}
if(i+1<n&&grid[i+1][j]==ch){
    if(!(i+1==px&&j==py)){
    if(visited[i+1][j]){
        return true;
    }
        if(dfs(i+1,j,i,j,visited,grid,ch)){
            return true;
        }
   }
}
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,(vector<char>(m,' ')));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    char ch;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]){
                if(dfs(i,j,-1,-1,visited,grid,grid[i][j])){
                    cout<<"Yes\n";
                    return 0;
                }
            }
        }
    }
    cout<<"No\n";
    return 0;

}