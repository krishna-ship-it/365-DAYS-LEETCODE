// https://leetcode.com/problems/out-of-boundary-paths/?envType=daily-question&envId=2024-01-26
#define mod 1000000007

class Solution {
public:
    int solution(int m, int n, int r, int c, int N, vector<vector<vector<int>>>& dp) {
        if (N < 0) {
            return 0; // Base case: out of moves
        }
        if (r < 0 || r >= m || c < 0 || c >= n) {
            return 1; // Base case: out of bounds
        }
        if (dp[r][c][N] != -1) {
            return dp[r][c][N];
        }
        long res = 0;
        res = (res + solution(m, n, r + 1, c, N - 1, dp)) % mod;
        res = (res + solution(m, n, r - 1, c, N - 1, dp)) % mod;
        res = (res + solution(m, n, r, c + 1, N - 1, dp)) % mod;
        res = (res + solution(m, n, r, c - 1, N - 1, dp)) % mod;
        return dp[r][c][N] = res;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));

        return solution(m, n, startRow, startColumn, maxMove, dp);
    }
};