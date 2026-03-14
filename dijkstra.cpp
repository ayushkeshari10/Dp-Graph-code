#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>> n>>m;
    vector<vector<pair<int,int>>>adj(n+1);
    vector<int>parent(n+1,-1);
    vector<bool>visited(n+1,0);
    int u,v,w;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int>dis(n+1,INT_MAX);
    dis[1]=0;
    pq.push({0,1});
    while(!pq.empty()){
        int d=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        if(visited[node]){
            continue;
        }
        visited[node]=true;
        for(auto &x:adj[node]){
            int neigh=x.first;
            int wt=x.second;
            if(!visited[neigh]&&d+wt<dis[neigh]){
                dis[neigh]=d+wt;
                pq.push({dis[neigh],neigh});
                parent[neigh]=node;
            }
        }
    }
    if(dis[n]==INT_MAX){
        cout<<-1;
        return 0;
    }
    vector<int>path;
    int curr=n;
    while(curr!=-1){
        path.push_back(curr);
        curr=parent[curr];
    }
    reverse(path.begin(),path.end());
    for(int x:path){
        cout<<x<<" ";
    }
    return 0;





}