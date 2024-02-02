// https://leetcode.com/problems/sequential-digits/description/?envType=daily-question&envId=2024-02-02
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i=1;i<=9;i++)
        {
            int a = i;
            int b = i+1;
            while(b <= 9 && a <= high)
            {  
                a = a*10 + b;
                if(a >= low && a <= high)
                ans.push_back(a);
                b++;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};