class Solution {
  public:
  
  
  void dfs(vector<vector<int>>&adj,vector<bool>&visited,int start,vector<int>&component){
      visited[start]=true;
      component.push_back(start);
      for(int neigh:adj[start]){
          if(visited[neigh]==false){
              dfs(adj,visited,neigh,component);
          }
      }
      
  }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            int from=edges[i][0];
            int to=edges[i][1];
            adj[from].push_back(to);
            adj[to].push_back(from);
        }
        vector<bool> visited(V,false);
        vector<vector<int>> result;
           
        for(int i=0;i<V;i++){
           if(!visited[i]){
               vector<int> component;
             dfs(adj,visited,i,component);
             result.push_back(component);
        }
        }
        return result;
    }
};
