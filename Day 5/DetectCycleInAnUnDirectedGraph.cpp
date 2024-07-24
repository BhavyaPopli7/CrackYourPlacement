//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  bool checkCycle(vector<int> adj[],unordered_map<int,bool>&vis,int src){
      queue<int>q;
      unordered_map<int,int>parent;
      
      q.push(src);
      vis[src] = true;
      parent[src] =-1;
      
      while(!q.empty()){
          int node = q.front();
          q.pop();
          
          for(auto i : adj[node]){
              int x=i;
              if(!vis[x]){
                vis[x]= true;   
                q.push(x);
                 
                  parent[x]= node;
              }
              else if(vis[x] && x != parent[node]){
                  return true;
              }
          }
      }
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        unordered_map<int,bool>vis;
        bool ans=false;
        for(int i=0;i<V;i++){
            if(!vis[i]){
              ans =checkCycle(adj,vis,i);
              if(ans== true){
                  break;
              }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends