class Solution {
public:
    typedef pair<int,int>P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mpp;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }

      priority_queue<P,vector<P>,greater<P>>pq;

       for(auto i: mpp){
           int val = i.first;
           int freq = i.second;

           pq.push({freq,val});
       }

       while(pq.size() != k){
        pq.pop();
       }

       while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
       }
       return ans;
    }
};