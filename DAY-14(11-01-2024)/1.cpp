// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
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

    int maxAncestorDiff(TreeNode* root,int mini = 1000000,int maxi = 0) {
        if(root == NULL)
            return maxi-mini;
        maxi = max(maxi,root->val);
        mini = min(mini,root->val);
        return max(maxAncestorDiff(root->left,mini,maxi),maxAncestorDiff(root->right,mini,maxi));
    }
};