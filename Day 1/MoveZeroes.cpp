class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count =0;
        int index =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                count++;
            }
            else{
               nums[index++] = nums[i];
            }
        }
         int j = nums.size()-1;
        while(count--){
            nums[j] = 0;
            j--;
        }
    }
};