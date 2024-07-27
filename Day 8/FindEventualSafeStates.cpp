class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
         int v = graph.size();
         vector<vector<int>>revAdj(v);

         for(int i=0;i<v;i++){
            for(auto u:graph[i]){
                revAdj[u].push_back(i);
            }
         }
         unordered_map<int,int>indegree;
         for(int i=0;i<v;i++){
            for(auto val:revAdj[i]){
                 indegree[val]++;
            }
         }
         queue<int>qt;
         vector<int>ans;
        for(int i=0;i<v;i++){
            if(indegree[i] == 0){
                qt.push(i);
            }
        }

        while(!qt.empty()){
            int value = qt.front();
            qt.pop();
            ans.push_back(value);

            for(auto i:revAdj[value]){
                indegree[i]--;

                if(indegree[i] == 0){
                    qt.push(i);
                }
            }
        }
       sort(ans.begin(),ans.end());
       return ans;
    }
};