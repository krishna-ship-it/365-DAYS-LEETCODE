// https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/description/
// 10031. Smallest Missing Integer Greater Than Sequential Prefix Sum


class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        for(int i=1;i<nums.size() && nums[i-1]+1 == nums[i];i++)
            sum += nums[i];
        map<int,int> m;
        for(auto i : nums)
            m[i]++;
        
        for(int i=sum;i<=50;i++)
        {
            if(m.find(i) == m.end() && i >= sum)
                return i;
        }
        if(sum <= 50)
            return 51;
        return sum;
                
    }
};