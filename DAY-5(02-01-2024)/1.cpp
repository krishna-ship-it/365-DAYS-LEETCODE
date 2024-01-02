// 2610. Convert an Array Into a 2D Array With Conditions
// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/?envType=daily-question&envId=2024-01-02
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<vector<int>> ans;
        for(auto i:nums)
            m[i]++;
        int n = 0;
        while(1)
        {
        vector<int> v;
        for(auto i : m)
        {
            if(m[i.first] > 0)
            {
                v.push_back(i.first);
                n++;
            }
            m[i.first]--;
        }
        ans.push_back(v);
        if(n == nums.size())
            break;
        }
      
        return ans;
    }
};