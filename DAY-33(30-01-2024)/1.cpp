// https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/
class Solution {
public:
    int bs(vector<long long> &arr,int s,int e,int t)
    {
        int ans = -1;
        while(s <= e)
        {
            int m = s+(e-s)/2;
            if(arr[m] > t)
            {
                ans = m;
                s = m+1;
            }
            else
            {
                s = m+1;
            }
        }
        return ans;
    }
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long ans = -1;
        int n = nums.size();
        vector<long long> pre(n);
        pre[0] = nums[0];
        for(int i=1;i<n;i++)
            pre[i] = pre[i-1]+nums[i];
        for(int i = n-1;i>=2;i--)
        {
           int res = bs(pre,0,i-1,nums[i]);
           if(res != -1)
           {
               long long t = pre[res]+nums[i];
               ans = max(ans,t);
           }
        }
        return ans;
    }
};