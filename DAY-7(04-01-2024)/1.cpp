// 2870. Minimum Number of Operations to Make Array Empty
// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/description/?envType=daily-question&envId=2024-01-04
class Solution {
public:
    int minOperations(vector<int>& nums) {
       
        unordered_map<int,int> m;
        for(auto i : nums)
            m[i]++;
        int ans = 0;
        for(auto i : m)
        {
            if(i.second < 2)
                return -1;
            if(i.second %3 == 0)
                ans += i.second/3;
            else if(i.second %3 == 2)
                ans += i.second/3 + 1;
            else if(i.second % 3 == 1)
                ans += (i.second-4)/3 + 2;

        }
        return ans;
    }
};