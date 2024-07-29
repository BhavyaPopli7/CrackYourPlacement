class Solution {
public:
 bool checkBi(vector<vector<int>>& graph,int color[],int src){

     queue<int>qt;
        qt.push(src);
        color[src] = 0;

        while(!qt.empty()){
            int node = qt.front();
            qt.pop();

            for(int i:graph[node]){
                if(color[i] == -1){
                    color[i] = !color[node];
                    qt.push(i);
                }
                else if(color[i] == color[node]){
                    return false;
                }
            }
        }
              return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        int color[v];
        for(int i=0;i<v;i++) color[i] = -1;

        for(int i=0;i<v;i++){
            if(color[i] == -1){
              if(checkBi(graph,color,i) == false){
                    return false;
              }
            }
        }
        return true;
    }    
};