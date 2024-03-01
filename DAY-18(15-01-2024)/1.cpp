// https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> losers,winners;
        for(int i=0;i<matches.size();i++)
            losers[matches[i][1]]++;
        for(int i=0;i<matches.size();i++)
            if(losers.find(matches[i][0]) == losers.end())
                winners[matches[i][0]];
        vector<int> l,w;
        for(auto i: winners)
            w.push_back(i.first);
        for(auto i : losers)
            if(i.second == 1)
                l.push_back(i.first);
        vector<vector<int>> ans;
        sort(w.begin(),w.end());
        sort(l.begin(),l.end());
        ans.push_back(w);
        ans.push_back(l);
        return ans;



    }
};