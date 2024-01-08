// https://leetcode.com/problems/range-sum-of-bst/?envType=daily-question&envId=2024-01-08

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL)
            return 0;
        if(root->left  == NULL and root->right == NULL)
        {
            if(root->val >= low && root->val <= high)
                return root->val;
            else
                return 0;
        }
        if(root->val >= low && root->val <= high)
            return root->val + rangeSumBST(root->left,low,high) + rangeSumBST(root->right,low,high);
        else
return  rangeSumBST(root->left,low,high) + rangeSumBST(root->right,low,high);

    }
};