// https://leetcode.com/problems/power-of-two/submissions/1179846769/?envType=daily-question&envId=2024-02-19
class Solution {
public:
    bool isPowerOfTwo(int n) {
     if( n == 1) return true; 
        else if ( n == 0) return false;
        else if( n % 2 != 0) return false;
        
        return isPowerOfTwo(n / 2);
    }
};