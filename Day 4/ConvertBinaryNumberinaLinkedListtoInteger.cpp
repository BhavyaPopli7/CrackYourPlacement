class Solution {
public:
    int getDecimalValue(ListNode* head) {
        vector<int>number;

        while(head!=NULL){
            number.push_back(head->val);
            head = head->next;
        }

        reverse(number.begin(),number.end());
         
         int ans =0;
        for(int i=0;i<number.size();i++){
           ans = ans + pow(2,i)*number[i];
        }
        return ans;
    }
};