#include<bits/stdc++.h>
using namespace std;
void bfs(int i,int j,vector<vector<bool>>&visited,vector<vector<char>>&grid,queue<pair<int,int>>&q){
    int n=grid.size();
    int m=grid[0].size();
   q.push({i,j});
   while(!q.empty()){
    int r=q.front().first;
    int c=q.front().second;
    q.pop();
    int dx[]={0,0,1,-1};
    int dy[]={1,-1,0,0};
    for(int k=0;k<4;k++){
        int nr=r+dx[k];
        int nc=c+dy[k];
        if(nr>=0&&nc>=0&&nr<n&&nc<m&&!visited[nr][nc]&&grid[nr][nc]=='.'){
            q.push({nr,nc});
            visited[nr][nc]=1;
        }
    }
   }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           cin>>grid[i][j];
        }
    }
    queue<pair<int,int>>q;
    vector<vector<bool>>visited(n,vector<bool>(m,0));
    long long count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='.'&&!visited[i][j]){
                visited[i][j]=true;
                bfs(i,j,visited,grid,q);
                count++;
            }
        }
    }
    cout<<count;
}