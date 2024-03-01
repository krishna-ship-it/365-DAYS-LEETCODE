// https://leetcode.com/problems/spiral-matrix-ii/


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
          vector<vector<int>> a(n,vector<int>(n));
          int x = 1;
          int l = 0;
          int r = n-1;
          int t  = 0;
          int b = n-1;
          int d = 0;
          while(l <= r && t <= b)
          {
            if(d == 0)
            {
                for(int i = l;i<=r;i++)
                {
                    a[t][i] = x;
                    x++;
                }
                t++;
                d = 1;
            }
            if(d == 1)
            {
                for(int i=t;i<=b;i++)
                {
                    a[i][r] = x;
                    x++;
                }
                r--;
                d = 2;
            }
            if(d==2 )
            {
                for(int i=r;i>=l;i--)
                {
                    a[b][i] = x;
                    x++;
                }
                b--;
                d = 3;
            }
            if(d == 3)
            {
                for(int i=b;i>=t;i--)
                {
                    a[i][l]=x;
                    x++;
                }
                l++;
                d = 0;
            }
          }
          return a;
    }
};