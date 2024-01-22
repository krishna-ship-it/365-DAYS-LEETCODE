// https://leetcode.com/problems/set-mismatch/?envType=daily-question&envId=2024-01-22

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<int> ans;
      for(auto i : nums)
      {
        m[i]++;
        if(m[i] == 2)
            ans.push_back(i);
      }
      for(int i=1;i<=nums.size();i++)
        if(m.find(i) == m.end())
            ans.push_back(i);

        return ans;
    
    }
};