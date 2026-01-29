#include<bits/stdc++.h>
using namespace std;
void dfs(int st,vector<bool>&cat,vector<vector<int>>&adj,int m,int parent,int ccout,int&ans){
   if(cat[st]==1){
    ccout++;
   }
   else{
    ccout=0;
   }
   if(ccout>m){
    return;
   }
   if(st!=1&&adj[st].size()==1){
    ans++;
    return;
   }
   for(int x:adj[st]){
    if(x==parent){
        continue;
    }
    else{
    dfs(x,cat,adj,m,st,ccout,ans);
   }
}
}
int main(){
    int n,m;
    cin>>n>>m;
    int ccount=0;
    vector<bool>cat(n+1);
    for(int i=1;i<=n;i++){
       int c;
       cin>> c;
       if(c==1){
        cat[i]=true;
       }
       else{
        cat[i]=false;
       }
    }
    vector<vector<int>>adj(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans=0;
     dfs(1,cat,adj,m,-1,0,ans);
     cout<< ans;
     return 0;
}