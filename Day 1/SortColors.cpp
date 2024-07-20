class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            bool isSwap = false;
            for(int j=0;j<nums.size()-1;j++){
                if(nums[j]>nums[j+1]){
                    isSwap = true;
                    swap(nums[j],nums[j+1]);
                }
            }
            if(isSwap == false) break;
        }
    }
};