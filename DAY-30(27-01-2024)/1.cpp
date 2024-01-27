// https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/description/
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
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<vector<int>> lvl;
        queue<TreeNode*> q;
        q.push(root);
        int l = 0;
        while(!q.empty())
        {
            int s = q.size();
            vector<int> v;
            for(int i=0;i<s;i++)
            {
                auto  f = q.front();
                q.pop();
                if(f->left)
                    q.push(f->left);
                if(f->right)
                    q.push(f->right);
                v.push_back(f->val);
            }
            if(l%2 !=  0)
                reverse(v.begin(),v.end());
            lvl.push_back(v);
            l++;
        }
        q.push(root);
        l = 0;
        while(!q.empty())
        {
            int s = q.size();
            for(int i=0;i<s;i++)
            {
                auto  f = q.front();
                f->val = lvl[l][i];
                q.pop();
                if(f->left)
                    q.push(f->left);
                if(f->right)
                    q.push(f->right);
            }
            l++;
        }
        return root;

    }
};