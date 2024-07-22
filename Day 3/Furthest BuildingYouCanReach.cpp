class Solution {
public:
    int furthestBuilding(vector<int>& nums, int bricks, int ladders) {
        int n = nums.size();
        priority_queue<int>qt;
        int i=0;
        for(i;i+1<n;i++){
          if(nums[i]>nums[i+1]){
            continue;
          }
          else{
            int d = nums[i+1] - nums[i];
            if(d <= bricks){
                bricks = bricks - d;
                qt.push(d);
            }
            else if(ladders>0){
                if(!qt.empty()){
                int val = qt.top();
                if(val>d){
                    bricks = bricks + val;
                    qt.pop();
                    qt.push(d);
                    bricks = bricks - d;
                }
                }
                ladders--;
            } 
            else{
                break;
            }
          }
        }
        return i;
    }
};