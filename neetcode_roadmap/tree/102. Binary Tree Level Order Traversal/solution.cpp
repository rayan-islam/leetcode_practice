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

    vector<vector<int>> orderTraversal(TreeNode* root,vector<vector<int>> ans, int level){
        if(level>=0 && level<ans.size()){
            ans[level].push_back(root->val);
        }else{
            vector<int> temp = {root->val};
            ans.push_back(temp);
        }
        if(root->left){
            ans=orderTraversal(root->left,ans,level+1);
        }
        if(root->right){
            ans=orderTraversal(root->right,ans,level+1);
        }
        return ans;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(!root){
            return ans;
        }
        return orderTraversal(root,ans,0);
    }
};
