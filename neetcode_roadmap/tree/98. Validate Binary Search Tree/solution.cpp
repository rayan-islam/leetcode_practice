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
    bool isBST(TreeNode* root, long  maxi, long mini ){
        
        if(!(root->val<maxi) || !(root->val>mini)){
            return false;
        }

        
        bool leftBool= true;
        if(root->left){
            leftBool=isBST(root->left,(maxi<root->val)?maxi:root->val,mini);
        }
        bool rightBool= true;
        if(root->right ){
            
            rightBool=isBST(root->right,maxi,(mini>root->val)?mini:root->val);
            
        }

        return rightBool && leftBool;
    }
    bool isValidBST(TreeNode* root) {
        return isBST(root,LONG_MAX,LONG_MIN);
    }
};
