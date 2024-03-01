class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = 0,zeros=0;
        for(auto i : s)
            if(i == '0')
                zeros++;
            else
                ones++;
        string ans = "";
        ans += string(ones-1,'1');
        ans += string(zeros,'0');
        ans.push_back('1');
        return ans;
    }
};