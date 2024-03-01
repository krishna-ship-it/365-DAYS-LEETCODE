// https://leetcode.com/contest/weekly-contest-382/problems/number-of-changing-keys/
class Solution {
public:
    int countKeyChanges(string s) {
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        int cnt = 0;
        for(int i=0;i<s.length()-1;i++)
        {
            if(s[i] != s[i+1])
                cnt++;
        }
        return cnt;
    }
};