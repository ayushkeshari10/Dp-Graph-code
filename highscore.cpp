#include<bits/stdc++.h>
using namespace std;
bool bfs(int node,vector<bool>&visited,vector<vector<int>>&adjrev,vector<bool>&badnode){
    queue<int>q;
    q.push(node);
    visited[node]=true;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        if(badnode[curr]){
            return true;
        }
        for(int x:adjrev[curr]){
            if(!visited[x]){
                visited[x]=true;
                q.push(x);
            }
        }
    }
    return false;
    
    
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges(m,vector<int>(3));
    vector<long long>dis(n+1,LLONG_MIN);
    dis[1]=0;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges[i][0]=u;
        edges[i][1]=v;
        edges[i][2]=w;

    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            int a=edges[j][0];
            int b=edges[j][1];
            int c=edges[j][2];
            if(dis[a]==LLONG_MIN){
                continue;
            }
            if(dis[a]+c>dis[b]){
                dis[b]=dis[a]+c;
            }
        }
    }
    vector<bool>badnode(n,false);
    bool check=false;
    for(int j=0;j<m;j++){
            int a=edges[j][0];
            int b=edges[j][1];
            int c=edges[j][2];
            if(dis[a]==LLONG_MIN){
                continue;
            }
            if(dis[a]+c>dis[b]){
                badnode[a]=true;
                check=true;
            }
}
if(check)
{
    vector<vector<int>>adjrev(n+1);
    vector<bool>visited(n+1,false);
for(int i=0;i<m;i++){
    int from=edges[i][0];
    int to=edges[i][1];
    adjrev[to].push_back(from);
}
if(bfs(n,visited,adjrev,badnode)){
    cout<<"-1";
}
else{
    cout<< dis[n];
}
}
else{
    cout<<dis[n];
}
}