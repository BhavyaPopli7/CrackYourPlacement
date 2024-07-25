/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int findLen(ListNode* temp){
        int len =0;
        while(temp!=NULL){
            len++;
            temp = temp->next;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head ==NULL) return NULL;
        ListNode* curr = head;
        ListNode* prev=NULL;
        ListNode* next;
        int count =0;
        if(findLen(head)<k){
            return head;
        }
        while(curr!=NULL && count<k){
            count++;
            next = curr->next;
            curr->next = prev;
            prev=curr;
            curr = next;
        }
        
        head->next = reverseKGroup(curr,k);

        return prev;
    }
};