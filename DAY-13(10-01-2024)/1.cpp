// 2385. Amount of Time for Binary Tree to Be Infected


// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/?envType=daily-question&envId=2024-01-10


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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,bool> visited;
        unordered_map<int,vector<int>> adj;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            auto f = q.front();
            q.pop();
            if(f->left != NULL && visited.find(f->left->val) == visited.end())
            {
                adj[f->val].push_back(f->left->val);
                adj[f->left->val].push_back(f->val);
                q.push(f->left);
            }
            if(f->right != NULL && visited.find(f->right->val) == visited.end())
            {
                adj[f->val].push_back(f->right->val);
                adj[f->right->val].push_back(f->val);
                q.push(f->right);
            }
        }
        // for(auto i : adj){
        //     cout<<i.first<<" ";
        //     for(auto j : adj[i.first])
        //         cout<<j<<" ";
        //     cout<<endl;
        // }
        queue<pair<int,int>> qu;
        visited.clear();
        qu.push({start,0});
        visited[start] = true;
        int ans = 0;
        while(!qu.empty())
        {
            auto x = qu.front();
            qu.pop();
            for(auto i : adj[x.first])
                if(visited.find(i) == visited.end())
                {
                    qu.push({i,x.second+1});
                    visited[i] = true;
                    ans =  max(ans,x.second+1);
                }
            
        }
        return ans;
    }
};