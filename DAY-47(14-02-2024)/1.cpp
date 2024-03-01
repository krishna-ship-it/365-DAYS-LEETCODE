// https://leetcode.com/problems/rearrange-array-elements-by-sign/?envType=daily-question&envId=2024-02-14
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans,neg,pos;
        for(auto i : nums)  if(i < 0)   neg.push_back(i); else pos.push_back(i);
        for(int i=0;i<neg.size();i++)
        {
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        return ans;

    }
};