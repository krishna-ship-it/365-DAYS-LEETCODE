// https://leetcode.com/problems/determine-if-string-halves-are-alike/description/

class Solution {
public:
    bool check(char ch)
    {
        if(
            ch == 'a'|| ch == 'e'|| ch == 'i'|| ch == 'o'|| ch == 'u'
            || ch == 'A'|| ch == 'E'|| ch == 'I'|| ch == 'O'|| ch == 'U'
        )
        return true;
        return false;
    }
    bool halvesAreAlike(string s) {
        int cnt=0;
        for(int i=0;i<s.size()/2;i++)
            if(check(s[i]))
                cnt++;
        for(int i = s.size()/2;i<s.size();i++)
            if(check(s[i]))
                cnt--;
        
        return cnt == 0;
        
    }
};