/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   void postOrder(TreeNode* root,vector<int>&a){
      if(root == NULL){
        a.push_back(INT_MAX);
        return;
      }  
     
      postOrder(root->left,a);
      postOrder(root->right,a);
      a.push_back(root->val);
   }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int>a;
        vector<int>b;
        postOrder(p,a);
        postOrder(q,b);

        if(a==b){
            return true;
        }
        else{
            return false;
        }
    }
};