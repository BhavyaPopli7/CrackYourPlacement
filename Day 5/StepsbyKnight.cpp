//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    queue<pair<pair<int,int>,int>>qt;
	    vector<vector<int>>vis(N,vector<int>(N,0));
	     int sr = KnightPos[1] - 1;
	     int sc = KnightPos[0] - 1;
	     
	     int fr = TargetPos[1] - 1;
	     int fc = TargetPos[0] - 1;
	     qt.push({{sr,sc},0});
	     int nrow[] = {1,-1,1,-1,-2,2,2,-2};
	     int ncol[] = {-2,-2,2,2,1,1,-1,-1};
	     
	     while(!qt.empty()){
	         int row = qt.front().first.first;
	         int col = qt.front().first.second;
	         int val = qt.front().second;
	         vis[row][col] = 1;
	         if(row==fr && col == fc){
	             return val;
	         }
	         
	         for(int i=0;i<8;i++){
	             int nr = row + nrow[i];
	             int nc = col + ncol[i];
	  
	             if(nr>=0 && nc>=0 && nr<N && nc<N && vis[nr][nc]!=1){
	                 vis[nr][nc] = 1;
	                qt.push({{nr,nc},val+1});
                      
	             }
	         }
	         qt.pop();
	     }
	   return -1;    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends