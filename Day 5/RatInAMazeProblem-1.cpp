//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
   
   void dfs(vector<vector<int>>&mat,int row,int col,vector<string>&ans,map<pair<int,int>,int>&vis,string &path){
       vis[{row,col}] = 1;
       
       int nrow[] = {1,0,-1,0};
       int ncol[] = {0,-1,0,1};
       
       for(int i=0;i<4;i++){
           int nr = row + nrow[i];
           int nc = col + ncol[i];
           
           if(nr>=0 && nc>=0 && nr<mat.size() && nc<mat[0].size() && mat[nr][nc]==1 && vis[{nr,nc}]!=1){
               if(i == 0){
                   path += 'D';
               }
               if(i == 1){
                   path +='L';
               }
               if(i == 2){
                   path += 'U';
               }
               if(i == 3){
                   path += 'R';
               }
               dfs(mat,nr,nc,ans,vis,path);
               if(nr == mat.size()-1 && nc == mat[0].size()-1){
                   ans.push_back(path);
               }
               path.pop_back();
               vis[{nr,nc}] = 0;
           }
       }
   }
  
    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
      vector<string>ans;
      map<pair<int,int>,int>vis;
      string path ="";
      
      if(mat[0][0] == 1){
          int sr = 0;
          int sc = 0;
       dfs(mat,sr,sc,ans,vis,path);
      }
      else{
          return ans;
      }
       return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends