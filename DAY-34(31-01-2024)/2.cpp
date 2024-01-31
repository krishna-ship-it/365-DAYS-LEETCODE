// https://leetcode.com/problems/count-good-nodes-in-binary-tree/
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
    int goodNodes(TreeNode* root,int curr = INT_MIN) {
        
        if(root->left == NULL && root->right == NULL)
        {
            if(curr == INT_MIN || curr <= root->val) return 1;
            return 0;
        }
        if(curr == INT_MIN)
        {
            int a = 0,b=0;
            if(root->left)
                a = goodNodes(root->left,root->val);
            if(root->right)
                b = goodNodes(root->right,root->val);
            return a+b+1;
        }
        else
        {
            int a = 0,b=0;
            if(root->left)
                a = goodNodes(root->left,max(root->val,curr));
            if(root->right)
                b = goodNodes(root->right,max(root->val,curr));
            int t = curr <= root->val ? 1 : 0;
            return a+b+t;
        }
    }
};