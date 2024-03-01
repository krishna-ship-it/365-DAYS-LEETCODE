// https://leetcode.com/problems/house-robber/description/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        for(int i=0;i<n;i++)
        {
            if(i==0)
                dp[0] = nums[0];
            else
            {
                int pick = nums[i];
                int notpick = 0;
                if(i > 1)
                    pick += dp[i-2];
                if(i > 0)
                    notpick += dp[i-1];
                dp[i] = max(pick,notpick);
            }
        }
        return dp[n-1];
    }
};