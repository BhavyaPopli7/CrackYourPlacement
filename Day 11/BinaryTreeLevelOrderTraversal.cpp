class Solution {
    vector<vector<int>> levelOrder(TreeNode* root,vector<vector<int>>&ans){
        queue<TreeNode*>q;
        if(root==NULL){
            return ans;
        }
        else{
            q.push(root);
        }

        while(!q.empty()){
            vector<int>length;
            int n=q.size();
            for(int i=0;i<n;i++){
                length.push_back(q.front()->val);
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            ans.push_back(length);
        }
        return ans;
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        levelOrder(root,ans);
        return ans;
    }
};