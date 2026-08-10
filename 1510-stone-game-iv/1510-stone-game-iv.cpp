class Solution {
    public :
    bool winnerSquareGame(int n) {
        vector<vector<int>> dp(2,vector<int>(n+1,-1));
        // Intuition: plain recursive minimax, Alice maximizes, Bob minimizes, no caching
        return game(n, true,dp);
    }

    private:
     bool game(int n, bool isAlice,vector<vector<int>> &dp) {
        if (n == 0) return !isAlice;
        int val = isAlice ? 1:0;
        if(dp[val][n]!=-1) return dp[val][n];
        for (int i = 1; i * i <= n; i++) {
            if (isAlice) {
                if (game(n - i * i, false,dp)) return dp[val][n] = true;
            } else {
                if (!game(n - i * i, true,dp)) return dp[val][n] = false;
            }
        }
        return dp[val][n] = !isAlice;
    }
};