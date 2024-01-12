// https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/
class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        long long x,y,z;
        if(num%3 != 0)
            return {};
        y = num/3;
        x = y-1;
        z = y+1;
        return {x,y,z};

    }
};