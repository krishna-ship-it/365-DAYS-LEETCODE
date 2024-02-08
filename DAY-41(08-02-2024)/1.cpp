// https://leetcode.com/problems/perfect-squares/?envType=daily-question&envId=2024-02-08
class Solution {
public:
    int solve(vector<vector<int>> &dp,int target,int idx,vector<int> &v)
    {
        if(idx >= v.size())
        {
            if(target != 0)
                return 1e7;
            else
                return 0;
        }
        if(dp[idx][target] != -1)
            return dp[idx][target];
        
        int a = INT_MAX,b = INT_MAX;
        a = solve(dp,target,idx+1,v);
        if(target >= v[idx])
            b = 1+ min(solve(dp,target-v[idx],idx+1,v),solve(dp,target-v[idx],idx,v));
        return dp[idx][target] = min(a,b);
    }
    int numSquares(int n) {
        vector<int> v;
        for(int i=1;i<=n;i++)
        {
            if(i*i <= n)
                v.push_back(i*i);
            else
                break;
        }
        vector<vector<int>> dp(v.size(),vector<int>(n+1,-1));
        return solve(dp,n,0,v);
       
    }
};