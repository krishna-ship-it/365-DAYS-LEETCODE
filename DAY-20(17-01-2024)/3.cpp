// // https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii/
// class Solution {
// public:
//     int solve(string s,string t)
//     {
//         unordered_map<char,int> m;
//         for(auto i : s)
//             m[i]++;
//         int ans = 0;
//         for(auto i : t)
//         {
//             if(m.find(i) == m.end())
//                 ans++;
//             else
//             {
//                 m[i]--;
//                 if(m[i] == 0)
//                     m.erase(i);
//             }
//         }

//         return  ans + s.size()-(t.size()-ans) ;

//     }
//     int minSteps(string s, string t) {
//         return solve(s,t);
        
//     }
// };

#include <bits/stdc++.h>
using namespace std;
int solve(int h,int k,int y1,int y2)
{
    if(h%y1 == 0)
    {
        if(h/y1 > k)
        {
            int x = (h/y1 - k)*y1;
            if(x%y2)
            {
                return (h/y1) + x/y2 + 1;
            }
            else{
                return (h/y1) + x/y2;
            }
        }
        else{
            return h/y1;
        }
    }
    else{
        if(h/y1 > k)
        {
            int x = (h/y1 - k)*y1;
            if(x%y2)
            {
                return (h/y1) + x/y2;
            }
            else{
                return (h/y1) + x/y2;
            }
        }
        else{
            int r = h%y1;
           
            if(r%y2 != 0)
            {
                return h/y1 + r/y2 + 1;
            }
            else{
                return h/y1 + r/y2 ;
            }
            
        } 
    }
}
int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--)
    {
        int h , x , y1 , y2 , k;
        cin>>h>>x>>y1>>y2>>k;
        int countl=0;
        int countg=0;
        int c=0;
    
        if(h%x == 0)
            countg = h/x;
        else
            countg = h/x + 1;
       
       cout<<min(countg,solve(h,k,y1,y2))<<endl;
        
    }
}