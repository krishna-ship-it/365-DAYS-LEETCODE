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
    bool isEvenOddTree(TreeNode* root) {
        int lvl = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int s = q.size();
            vector<int> v;
            for(int i=0;i<s;i++)
            {
                v.push_back(q.front()->val);
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
            if(lvl == 0)
            {
                if(v[0]%2 == 0)
                    return false;
                else {lvl++;continue;}
                
            }
            if(lvl%2 == 0)
            {
                if(v.size()==1)
                {
                    if(v[0]%2 == 0)
                        return false;
                }
                for(int i=0;i<v.size()-1;i++)
                {
                    if(v[i]%2 != 1)
                        return false;
                    if(v[i] >= v[i+1])
                        return false;

                }
                if(v.back()%2 == 0)
                    return false;
            }
            else
            {
                if(v.size()==1)
                {
                    if(v[0]%2 == 1)
                        return false;
                }
                for(int i=0;i<v.size()-1;i++)
                {
                    if(v[i]%2 != 0)
                        return false;
                    if(v[i] <= v[i+1])
                        return false;
                }
                if(v.back()%2==1)
                    return false;

            }
            lvl++;
        }
        return true;
    }
};