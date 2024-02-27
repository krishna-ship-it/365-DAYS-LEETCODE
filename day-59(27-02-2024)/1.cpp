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
    int height(TreeNode *root)
    {
        if(root == NULL)
            return 0;
        // if(root->left == NULL && root->right == NULL)
        //     return 0;
        return max(height(root->left),height(root->right)) + 1;
    }
    int solve(TreeNode *root)
    {
        if(root == NULL)
            return 0;  
        if(root->left == NULL && root->right == NULL)
            return 0;
        int op1 = solve(root->left);
        int op2 = solve(root->right);
        int op3 = height(root->left) + height(root->right) ;
        return max(op1,max(op2,op3));
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        return solve(root);
        
    }
};