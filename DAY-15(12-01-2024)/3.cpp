// https://leetcode.com/problems/sum-of-beauty-of-all-substrings/description/
class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        
        for(int i=0;i<s.size();i++)
        {
            unordered_map<char,int> m;
            int l = s.size();
            int h = 0;
           
           for(int j=i;j<s.size();j++)
           {
               
               m[s[j]]++;
               if(m.size() > 1)
               {
                   int l = s.size();
                   int h = 0;
                   for(auto a : m)
                   {
                       l = min(l,a.second);
                       h = max(h,a.second);
                   }
                   ans += (h-l);
               }
              
               
           }
        }
        return ans;
    }
};