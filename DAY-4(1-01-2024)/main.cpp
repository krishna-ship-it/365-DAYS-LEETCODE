// 455. Assign Cookies
// https://leetcode.com/problems/assign-cookies/description/?envType=daily-question&envId=2024-01-01
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cookiesNums = s.size();
        if(cookiesNums == 0)  return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int maxNum = 0;
        int cookieIdx = cookiesNums - 1;
        int childIndex = g.size() - 1;
        while(cookieIdx >= 0 && childIndex >=0){
            if(s[cookieIdx] >= g[childIndex]){
                maxNum++;
                cookieIdx--;
                childIndex--;
            }
            else{
                childIndex--;
            }
        }
        return maxNum;
    }
};