#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n+1);
    vector<bool>visited(n+1,0);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
    pq.push({0,1});
    long long mincost=0;
    while(!pq.empty()){
        int node=pq.top().second;
        long long cost=pq.top().first;
        pq.pop();
        if(visited[node]){
            continue;
        }
        visited[node]=true;
        mincost+=cost;
        for(int i=0;i<adj[node].size();i++){
            int neigh=adj[node][i].first;
            int p=adj[node][i].second;
            if(!visited[neigh]){
            pq.push({p,neigh});
        }
    }
}
    bool check=false;
    for(int i=1;i<n;i++){
        if(!visited[i]){
          check=true;
        }
    }
    if(check){
        cout<<"IMPOSSIBLE";
    }
    else{
        cout<<mincost;
    }
    return 0;
}