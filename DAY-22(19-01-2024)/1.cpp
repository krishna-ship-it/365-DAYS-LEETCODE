// https://leetcode.com/problems/next-greater-element-iii/
class Solution {
public:
    int nextGreaterElement(int n) {
        if(n == INT_MAX)
            return -1;
        string s = to_string(n);
        int i = s.size()-2;
        while(i >= 0)
        {
            if(s[i] < s[i+1])
            {
                int j = s.size()-1;
                while(j > i)
                {
                    if(s[j] > s[i])
                    {
                        swap(s[j],s[i]);
                        reverse(s.begin()+i+1,s.end());
                        cout<<"s = "<<s<<endl;
                        if(s > to_string(INT_MAX) && s.size() == to_string(INT_MAX).size()){
                            cout<<"s = "<<s<<" maxi = "<<to_string(INT_MAX);
                            return -1;
                        }
                        return stoi(s);
                    }
                    else
                    {
                        j--;
                    }
                }
            }
            else
                i--;
        }
        return -1;

    }
};