// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/
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
    unordered_map<int,int> freq;
    int ans = 0;
    void dfs(TreeNode *root)
    {
        if(root->left == NULL && root->right == NULL)
        {
            freq[root->val]++;
            int even=0,odd=0;
            for(auto i : freq)
                i.second%2 == 0 ? even++:odd++;
            freq[root->val]--;
            if(freq[root->val]==0)
                freq.erase(root->val);
            if(freq.size() == 0)
            {
                ans++;
            }
            else
            {
                if(odd > 1)
                    return;
                ans++;
                return;
            }

        }
        
        freq[root->val]++;
        if(root->left)
            dfs(root->left);
        if(root->right)
            dfs(root->right);
        freq[root->val]--;
        if(freq[root->val] == 0)
            freq.erase(root->val);   
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root);
        return ans;
    }
};