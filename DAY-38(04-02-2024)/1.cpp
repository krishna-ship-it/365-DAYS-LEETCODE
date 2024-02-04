// https://leetcode.com/problems/minimum-window-substring/description/?envType=daily-question&envId=2024-02-04
class Solution {
public:
    string minWindow(string s, string t) {
         int m=s.size(), n=t.size();
        unordered_map<char, int> mp;
        
        int ans = INT_MAX; 
        int start = 0; 
        
        for(auto x:t)
            mp[x]++;
        
        int count = mp.size();
        
        int i = 0, j = 0;

        while (j < s.length()) {
            mp[s[j]]--;
            if (mp[s[j]] == 0)
                count--;

        
            while (count == 0) {
                if (ans > j - i + 1) {
                    ans = j - i + 1;
                    start = i;
                }
                mp[s[i]]++;
                  if (mp[s[i]] == 1)
                        count++;
                    i++;
                }
            j++;
        }
        if (ans != INT_MAX)
            return s.substr(start, ans);
        else
            return "";
    }
};