class Solution {
public:
    bool isPalindrome(string s)
    {
        int l = 0;
        int h = s.size()-1;
        while(l <= h )
            if(s[l++] != s[h--])
                return false;
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto i : words)
            if(isPalindrome(i))
                return i;
        return "";
    }
};