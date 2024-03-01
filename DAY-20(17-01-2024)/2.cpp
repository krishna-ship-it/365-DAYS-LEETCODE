// https://leetcode.com/problems/groups-of-special-equivalent-strings/description/
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& w) {
        unordered_set<string> st;
        for(int i = 0;i<w.size();i++)
        {
            string even = "",odd = "";
            for(int j = 0;j<w[i].size();j++)
            {
                if(j%2) odd+=w[i][j];
                else even+=w[i][j];
            }
            sort(even.begin(),even.end());
            sort(odd.begin(),odd.end());
            st.insert(even+odd);
        }
        return st.size();
        
    }
};