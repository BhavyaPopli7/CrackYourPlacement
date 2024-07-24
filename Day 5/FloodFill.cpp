class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        int originalColor = image[sr][sc];

        if(originalColor == color) return image;

        queue<pair<int,int>>qt;
        qt.push({sr,sc});
        
        int nrow[] = {0,-1,0,1};
        int ncol[] = {1,0,-1,0};

        while(!qt.empty()){
            int row = qt.front().first;
            int col = qt.front().second;

            image[row][col] = color;

            for(int i=0;i<4;i++){
                int nr = row + nrow[i];
                int nc = col + ncol[i];
                if(nr>=0 && nc>=0 && nr<m && nc<n && image[nr][nc] == originalColor){
                    qt.push({nr,nc});
                }
            }

            qt.pop();
        }

        return image;
    }
};