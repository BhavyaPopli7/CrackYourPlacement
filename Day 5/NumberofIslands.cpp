class Solution {
public:
   void dfs(vector<vector<char>>&grid,int row,int col,map<pair<int,int>,int>&vis){
        
        vis[{row,col}] = 1;

        int nrow[] = {1,0,-1,0};
        int ncol[] = {0,1,0,-1};

        for(int i=0;i<4;i++){
            int nr = row + nrow[i];
            int nc = col + ncol[i];

            if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && grid[nr][nc] == '1' && vis[{nr,nc}]!=1){
                dfs(grid,nr,nc,vis);
            }
        }
   }

    int numIslands(vector<vector<char>>& grid) {
        map<pair<int,int>,int>vis;
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && vis[{i,j}]!=1){
                    count++;
                    dfs(grid,i,j,vis);
                }
            }
        }
        return count;
    }
};