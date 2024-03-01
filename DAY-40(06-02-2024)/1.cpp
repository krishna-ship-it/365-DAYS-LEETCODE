// https://leetcode.com/problems/sort-characters-by-frequency/?envType=daily-question&envId=2024-02-07
class Solution {
public:
    static bool cmp(pair<char,int> &a,pair<char,int> &b)
    {
        return a.second>b.second;
    }
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(auto i : s)
            m[i]++;
        vector<pair<char,int>> v;
        for(auto i : m)
            v.push_back(i);
        sort(v.begin(),v.end(),cmp);
        string ans;
        for(auto i:v)
            ans += string(i.second,i.first);
        return ans;
    }
};