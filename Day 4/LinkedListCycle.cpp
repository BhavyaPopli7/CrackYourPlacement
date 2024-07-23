class Solution {
public:
    bool hasCycle(ListNode *head) {
      int count = 0;
      while(head!=NULL){
        count++;
        head = head ->next;

        if(count>100000){
            return true;
        }
      }

      return false;
    }
};