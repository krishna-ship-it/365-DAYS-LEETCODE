// https://leetcode.com/problems/determine-if-two-strings-are-close/description/?envType=daily-question&envId=2024-01-14
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char,int> m1,m2;
        for(auto i : word1) m1[i]++;
        for(auto i : word2) m2[i]++;
        if(m1.size() != m2.size())
            return false;
        for(auto i : word1)
            if(m2.find(i) == m2.end())
                return false;
        vector<int> v1,v2;
        for(auto i : m1) v1.push_back(i.second);
        for(auto i : m2) v2.push_back(i.second);
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        for(int i=0;i<v1.size();i++)
            if(v1[i] != v2[i])
                return false;
        return true;

    }
};