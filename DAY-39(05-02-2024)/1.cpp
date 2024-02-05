// https://leetcode.com/problems/first-unique-character-in-a-string/description/
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> m;
        for(auto x : s)
            m[x]++;
        for(int i=0;i<s.size();i++)
            if(m[s[i]] == 1)
                return i;
        return -1;
    }
};