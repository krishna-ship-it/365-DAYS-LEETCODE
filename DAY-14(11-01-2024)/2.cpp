// https://leetcode.com/problems/find-the-score-of-all-prefixes-of-an-array/
class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> c(n);
        long long maxi = nums[0];
        c[0] = 2*nums[0];
        for(int i=1;i<n;i++)
        {
            maxi = max(maxi,(long long)nums[i]);
            c[i] = nums[i]+maxi;
        }
        vector<long long> ans(n);
        ans[0] = c[0];
        for(int i=1;i<n;i++)
            ans[i] = ans[i-1]+c[i];
        return ans;

    }
};