class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int ans = INT_MIN;

        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }

        int n = nums.size();
        n = n/2;

        for(auto i:mpp){
            if(i.second>n){
                ans = max(ans,i.first);
            }
        }
        return ans;
    }
};