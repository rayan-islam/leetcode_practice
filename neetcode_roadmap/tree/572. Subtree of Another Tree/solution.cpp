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
    bool sameTree(TreeNode* p, TreeNode* q){
        if(!p && !q)
            return true;
        if((!p && q)||(!q && p))
            return false;
        if(p->val != q->val){
            return false;
        }
        return sameTree(p->left,q->left) && sameTree(p->right,q->right); 
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        bool mid=sameTree(root,subRoot);
        //onek shomoy eta subtree hoise, sametree dekhay, kintu shob same tree function diye recursion dile
        // tokhon subtree onek niche hoile left subtree true dileo right subtree false dile pore false dey,
        // tai ei kaarshaji kora lagse
        
 
        return isSubtree(root->left , subRoot) || isSubtree(root->right , subRoot) || mid; 
    }
};
