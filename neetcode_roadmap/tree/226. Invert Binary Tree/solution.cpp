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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;                //root null hoite pare
        TreeNode* leftSubtree = root->left;   //mathay rakhte hobe eta pointer tai temp arekta 
        TreeNode* rightSubtree = root->right; //variable niye then recursion e pathaite hobe

    // Recursively invert the left and right subtrees
        root->left = invertTree(rightSubtree);
        root->right = invertTree(leftSubtree);
        return root;
    }
    
};
