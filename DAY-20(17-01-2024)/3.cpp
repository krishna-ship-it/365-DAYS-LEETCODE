// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii/
class Solution {
public:
    int solve(string s,string t)
    {
        unordered_map<char,int> m;
        for(auto i : s)
            m[i]++;
        int ans = 0;
        for(auto i : t)
        {
            if(m.find(i) == m.end())
                ans++;
            else
            {
                m[i]--;
                if(m[i] == 0)
                    m.erase(i);
            }
        }

        return  ans + s.size()-(t.size()-ans) ;

    }
    int minSteps(string s, string t) {
        return solve(s,t);
        
    }
};