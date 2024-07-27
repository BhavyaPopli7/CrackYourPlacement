//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        queue<int>qt;
        vector<int>indegree(V);
        vector<int>ans;
        for(int i=0;i<V;i++){
            for(auto j: adj[i]){
                indegree[j]++;
            }
        }
        
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                qt.push(i);
            }
        }
        while(!qt.empty()){
           int val = qt.front();
           ans.push_back(val);
           qt.pop();
           
           for(auto i: adj[val]){
               indegree[i]--;
               if(indegree[i] == 0){
                   qt.push(i);
               }
           }
        }
        
        if(ans.size() == V){
            return 0;
        }
        else{
            return 1;
        }
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends