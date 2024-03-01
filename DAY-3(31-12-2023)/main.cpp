// 1190. Reverse Substrings Between Each Pair of Parentheses
// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/
class Solution {
public:
    string reverseParentheses(string s) {
        bool isOpen =  false;
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] ==  '(' || s[i] != ')')
                st.push(s[i]);
            else
            {
                string temp;
                while(!st.empty() && st.top() != '(')
                {
                    temp.push_back(st.top());
                    st.pop();
                }
                if(!st.empty())
                    st.pop();
                for(auto  x:temp)
                    st.push(x);
            }
        }
        string ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
       reverse(ans.begin(),ans.end());

        return ans;
    }

};