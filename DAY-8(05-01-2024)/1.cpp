// 680. Valid Palindrome II
// https://leetcode.com/problems/valid-palindrome-ii/description/
class Solution {
public:
    bool check(string s,int l,int r)
    {
        while( l < r)
        {
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l =  0;
        int r =  s.size()-1;
        while(l < r)
        {
            if(s[l] == s[r])
                l++,r--;
            else
                break;
        }
        return check(s,l+1,r) || check(s,l,r-1);
    }
};