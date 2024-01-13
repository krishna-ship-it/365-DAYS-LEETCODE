// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/
class Solution {
public:
    
    int minSteps(string s, string t) {
        unordered_map<char,int> m;
        for(auto i : s)
            m[i]++;
        int ans = 0;
        for(auto i : t)
        {
            if(m.find(i) != m.end())
            {
                m[i]--;
                if(m[i] == 0)
                    m.erase(i);
            }
            else
                ans++;
        }
        return ans;
    }
};