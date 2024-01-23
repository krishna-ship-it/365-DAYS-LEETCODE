// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/?envType=daily-question&envId=2024-01-23
class Solution {
public:
    int maxLength(vector<string>& arr,int idx=0,string pre="") {
        set<char> s(pre.begin(),pre.end());
        if(s.size() != pre.size())
            return 0;
        int ans = pre.size();
        for(int i=idx;i<arr.size();i++)
        {
            ans = max(ans,maxLength(arr,i+1,pre+arr[i]));
        }
        return ans;
    }
};