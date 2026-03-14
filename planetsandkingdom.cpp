#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<vector<int>>&adj,vector<bool>&visited,stack<int>&s){
    visited[node]=true;
    for(int x:adj[node]){
        if(!visited[x]){
            dfs(x,adj,visited,s);
        }
    }
    s.push(node);
}
 void rdfs(int node,vector<vector<int>>&radj,vector<bool>&visited1,int count,vector<int>&kingdom){
   visited1[node]=true;
   kingdom[node]=count;
   for(int x:radj[node]){
    if(!visited1[x]){
        rdfs(x,radj,visited1,count,kingdom);
    }
   }
 }
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    vector<vector<int>>radj(n+1);
    for(int i=0;i<m;i++){
        int from;
        int to;
        cin>>from>>to;
        adj[from].push_back(to);
        radj[to].push_back(from);
    }
    vector<bool>visited(n+1,0);
    vector<bool>visited1(n+1,0);
    vector<int>kingdom(n+1,0);
    stack<int>s;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i,adj,visited,s);
        }
    }
    int count=0;
    while(!s.empty()){
        int st=s.top();
        s.pop();
        if(!visited1[st]){
            count++;
            rdfs(st,radj,visited1,count,kingdom);
        }
    }
    cout<<count<<"\n";
    for(int i=1;i<=n;i++){
        cout<<kingdom[i]<<" ";
    }
}