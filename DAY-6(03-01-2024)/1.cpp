// https://leetcode.com/problems/number-of-laser-beams-in-a-bank/
// 2125. Number of Laser Beams in a Bank
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int pre_no = 0;
        for(auto i : bank[0])
            pre_no += (i=='1');
                
        
        for(int i=1;i<bank.size();i++)
        {
            int no = 0;
            for(auto j : bank[i])
                no += (j=='1');
            if(no > 0)
                ans += (no*pre_no),pre_no = no;
        }
        return ans;
    }
};