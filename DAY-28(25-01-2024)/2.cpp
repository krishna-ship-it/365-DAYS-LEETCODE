// https://leetcode.com/problems/number-of-zero-filled-subarrays/
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int cnt = 0;
        long long ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] != 0)
            {
                cout<<cnt<<endl;
                ans += (cnt*1LL*(cnt+1))/2;
                cnt= 0;
            }
            else
                cnt++;
        }
        if(cnt > 0)
        ans += (cnt*1LL*(cnt+1))/2;
        return ans;
    }
};