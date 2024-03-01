// https://leetcode.com/problems/shortest-palindrome/
class Solution {
public:
    void fillLPS(string s,vector<int> &lps)
    {
        lps[0] = 0;
        int i=1;
        int len = 0;
        while(i < s.size())
        {
            if(s[len]==s[i])
            {
                lps[i] = len+1;
                len++;
                i++;
            }
            else{
                if(len == 0)
                {
                    lps[i] = 0;
                    i++;
                }
                else
                    len = lps[len-1];
            }
        }

    }
    string shortestPalindrome(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        t = s + "#" + t;
        vector<int> lps(t.size());
        fillLPS(t,lps);
        int l = lps[t.size()-1];
        t = s.substr(l);
        reverse(t.begin(),t.end());

        return t + s;
    }
};