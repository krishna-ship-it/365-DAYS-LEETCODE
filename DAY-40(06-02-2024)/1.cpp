// https://leetcode.com/problems/group-anagrams/?envType=daily-question&envId=2024-02-06
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        for(int i=0;i<strs.size();i++)
        {
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            m[temp].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto i : m)
            ans.push_back(i.second);
        return ans;
    }
};