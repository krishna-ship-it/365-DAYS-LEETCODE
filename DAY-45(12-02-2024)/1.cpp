// https://leetcode.com/problems/majority-element/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
         int count = 0;
        int el = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(count == 0)
            {
                el = nums[i];
            }
            if(el == nums[i])
                count++;
            else
                count--;
                
        }
        return el;
    }
};