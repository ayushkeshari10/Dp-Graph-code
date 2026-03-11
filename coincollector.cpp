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
void rdfs(int node,vector<vector<int>>&radj,vector<bool>&visited1,int count,vector<int>&compo){
    visited1[node]=true;
    compo[node]=count;
    for(int x:radj[node]){
        if(!visited1[x]){
           rdfs(x,radj,visited1,count,compo);
        }
    }
}
long long solve(int node,vector<vector<int>>&cadj,vector<long long>&dp,vector<long long>&compocoin){
    if(dp[node]!=-1){
        return dp[node];
    }
     long long best = 0;
    for(int x : cadj[node]){
        best = max(best, solve(x, cadj, dp, compocoin));
    }

    return dp[node] = best + compocoin[node];
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>coins(n+1);
    for(int i=1;i<=n;i++){
        cin>>coins[i];
    }
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
    stack<int>s;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i,adj,visited,s);
        }
    }
    vector<int>compo(n+1);
    int count=0;
    while(!s.empty()){
        int node=s.top();
        s.pop();
        if(!visited1[node]){
            count++;
            rdfs(node,radj,visited1,count,compo);
        }
    }
    vector<long long>compocoin(count+1,0);
    for(int i=1;i<=n;i++){
        compocoin[compo[i]]+=coins[i];
    }
    vector<vector<int>>cadj(count+1);
    for(int i=1;i<=n;i++){
        for(int x:adj[i]){
            if(compo[i]!=compo[x]){
                cadj[compo[i]].push_back(compo[x]);
            }
        }
    }
    vector<long long >dp(count+1,-1);
    long long ans=0;
    for(int i=1;i<=count;i++){
        ans=max(ans,solve(i,cadj,dp,compocoin));
    }
    cout<<ans;
}