// https://leetcode.com/problems/unique-number-of-occurrences/description/
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        for(auto i : arr)
            m[i]++;
        vector<int> v;
        for(auto i : m )
            v.push_back(i.second);
        sort(v.begin(),v.end());
        for(int i=0;i<v.size()-1;i++)
            if(v[i] == v[i+1])
                return false;
        return true;
    }
};