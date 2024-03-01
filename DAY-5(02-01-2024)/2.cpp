// 532. K-diff Pairs in an Array
// https://leetcode.com/problems/k-diff-pairs-in-an-array/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto i : nums)
            mp[i]++;
        int ans = 0;
        if(k == 0)
        {
            for(auto  i : mp)
            {
                if(mp[i.first] > 1)
                    ans++;
            }
        }
        else
        {
            for(auto i:mp)
            {
                int diff = i.first+k;
                if(mp.find(diff) != mp.end())
                    ans++;
            }
        }
        return ans;
    }
};